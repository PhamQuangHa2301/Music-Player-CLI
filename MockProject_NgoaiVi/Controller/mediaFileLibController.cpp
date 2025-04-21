#include "mediaFileLibController.h"

void mediaFileLibController::mainScreenController(std::string command, appData& data){
    if(command == "q"){
        data.setControlMode(MAIN_SCREEN);
    }
    else if(command == "a"){
        data.setControlMode(MEDIA_FILE_ADD_NEW_FILE);
    }
    else if(command == "b"){
        data.setControlMode(MEDIA_FILE_BROWSE_DIRECTORY);
    }
    else if(command == "s"){
        data.setControlMode(MEDIA_FILE_SELECT_MEDIA_FILE);
    }
}

void mediaFileLibController::addNewFilePath(std::string command, appData& data, std::string filename) {
    if(command == "q"){
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
        return;
    }

    // Kiểm tra nếu file có tồn tại và là .mp3
    std::ifstream testFile(command.c_str());
    if (!testFile.good() || (command.size() <= 4 || command.substr(command.size() - 4) != ".mp3")) {
        return;
    }
    testFile.close();

    // Mở file JSON và đọc nội dung
    json j;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> j;
        inFile.close();
    }

    // Đảm bảo mediaLibrary là mảng
    if (!j.contains("mediaLibrary") || !j["mediaLibrary"].is_array()) {
        j["mediaLibrary"] = json::array();
    }

    // Kiểm tra xem file đã tồn tại trong mediaLibrary chưa
    bool fileExists = false;
    for (const auto& item : j["mediaLibrary"]) {
        if (item == command) {
            fileExists = true;
            break;
        }
    }

    // Nếu không tồn tại, thêm file vào mediaLibrary
    if (!fileExists) {
        j["mediaLibrary"].push_back(command);

        // Ghi lại file JSON
        std::ofstream outFile(filename);
        outFile << j.dump(4);
        outFile.close();
        sharedControllerFunction::loadMediaFileLib(data, filename);
        sharedControllerFunction::loadMediaFileToPlaylist(filename);
        sharedControllerFunction::loadPlaylist(data, filename);
        sharedControllerFunction::loadCurrentPlaylist(data);
        sharedControllerFunction::loadSelectedPlaylist(data);
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    } else {
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    }
}

void mediaFileLibController::browseDirectory(std::string command, appData& data, std::string filename) {
    if(command == "q"){
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
        return;
    }

    json j;

    // Mở file JSON nếu tồn tại
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> j;
        inFile.close();
    }

    // Đảm bảo mediaLibrary là mảng
    if (!j.contains("mediaLibrary") || !j["mediaLibrary"].is_array()) {
        j["mediaLibrary"] = json::array();
    }

    DIR* dir;
    struct dirent* entry;
    if ((dir = opendir(command.c_str())) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            std::string fileName = entry->d_name;
            if (fileName.size() > 4 &&
                (fileName.substr(fileName.size() - 4) == ".mp3" || fileName.substr(fileName.size() - 4) == ".wav")) {
                std::string fullPath = command + "/" + fileName;

                // Kiểm tra xem file đã tồn tại trong mediaLibrary chưa
                bool fileExists = false;
                for (const auto& item : j["mediaLibrary"]) {
                    if (item == fullPath) {
                        fileExists = true;
                        break;
                    }
                }

                // Nếu không tồn tại, thêm file vào mediaLibrary
                if (!fileExists) {
                    j["mediaLibrary"].push_back(fullPath);
                } else {
                }
            }
        }
        closedir(dir);
    } else {
        return;
    }

    // Ghi lại file JSON
    std::ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();

    sharedControllerFunction::loadMediaFileLib(data, filename);
    sharedControllerFunction::loadMediaFileToPlaylist(filename);
    sharedControllerFunction::loadPlaylist(data, filename);
    sharedControllerFunction::loadCurrentPlaylist(data);
    sharedControllerFunction::loadSelectedPlaylist(data);
    data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
}

void mediaFileLibController::selectMediaFile(std::string command, appData& data){
    if(command == "q")
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    else {
        int index;
        try {
            index = std::stoi(command);
            if (index < 1 || index > static_cast<int>(data.getMediaLibrary().size())) {
            }
            index = index - 1;
            mediaFile smf = data.getMediaLibrary()[index];
            data.setSelectedMediaFile(smf);
            data.setControlMode(EDIT_MEDIA_FILE_MAIN_SCREEN);
        } 
        catch (const std::invalid_argument& e) {

        } 
        catch (const std::out_of_range& e) {

        }
    }
}