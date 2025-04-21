#include "playlistController.h"

void playlistManagerController::generalPlaylistController(std::string command, appData& data){
    if(command == "c"){ //create new playlist 
        data.setControlMode(PLAYLIST_MANAGER_CREATE_NEW_PLAYLIST_SCREEN);
    }
    else if (command == "s"){ //select playlist
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_SELECT_SCREEN);
    }
    else if (command == "q"){ //quit to main menu
        data.setControlMode(MAIN_SCREEN);
    }
}

void playlistManagerController::selectPlaylistController(std::string command, appData& data){
    if(command == "q")
        data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
    else {
        int index;
        try {
            index = std::stoi(command);
            if (index < 1 || index > static_cast<int>(data.getPlaylistList().size())) {
                throw std::out_of_range("Index out of range!");
            }
            index = index - 1;
            playlist spl = data.getPlaylistList()[index];
            data.setSelectedPlaylist(spl);
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        } 
        catch (const std::invalid_argument& e) {

        } 
        catch (const std::out_of_range& e) {

        }
    }
}

void playlistManagerController::selectedPlaylistController(std::string command, appData& data){
    if(command == "q"){
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_SELECT_SCREEN);
    }
    else if(command == "p"){
        data.setControlMode(PlAYLIST_MANAGER_PLAY_PLAYLIST);
    }
    else if(command == "a"){
        data.setControlMode(PLAYLIST_MANAGER_ADD_MEDIA_TO_PLAYLIST_SCREEN);
    }
    else if(command == "d"){
        data.setControlMode(PLAYLIST_MANAGER_DELETE_PLAYLIST);
    }
}

void playlistManagerController::createPLaylistController(std::string& filename, std::string command, appData& data) {
    // Đọc file JSON
    std::ifstream inFile(filename);
    json j;
    if (inFile.is_open()) {
        try {
            inFile >> j; // Đọc dữ liệu JSON vào biến j
        } catch (...) {
            data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
            return;
        }
        inFile.close();
    } else {
        data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
        return;
    }

    // Kiểm tra xem 'playlist' có trong JSON không
    if (!j.contains("playlist") || !j["playlist"].is_object()) {
        j["playlist"] = json::object();  // Nếu không có, tạo mới key 'playlist' dạng object
    }

    // Kiểm tra xem playlist đã tồn tại chưa
    if (j["playlist"].contains(command)) {
        data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
        return;
    }

    // Tạo playlist mới với tên là command
    j["playlist"][command] = json::array(); // Thêm playlist mới với tên là `command` (dữ liệu trống)

    // Lưu lại file JSON
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << j.dump(4);  // Ghi lại dữ liệu JSON vào file (indent 4 cho dễ đọc)
        outFile.close();
    } else {
    }
    sharedControllerFunction::loadPlaylist(data, filename);
    // Cập nhật chế độ điều khiển
    data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
}

void playlistManagerController::playPLaylist(appData& data){
    data.setCurrentPlaylist(data.getSelectedPlaylist());
    musicPlayController::playMusic(data);
    data.setControlMode(MUSIC_PLAY_MAIN_SCREEN);
}

void playlistManagerController::addMediaFileToPlaylist(std::string command, appData& data, std::string& filename) {
    if (command == "q"){
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
    }
    else {
        // Kiểm tra xem file có phải là .mp3 không
        if (command.size() <= 4 || command.substr(command.size() - 4) != ".mp3") {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }
        // Lấy playlist đã chọn từ appData
        playlist pl = data.getSelectedPlaylist();
        std::string playlistName = pl.getPlaylistName();

        // Đọc file JSON
        std::ifstream inFile(filename);
        json j;
        if (!inFile.is_open()) {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }

        try {
            inFile >> j;  // Đọc dữ liệu JSON vào biến j
        } catch (...) {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }
        inFile.close();
        
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
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    } else {
        std::cout << "File đã tồn tại trong thư viện.\n";
    }
        // Kiểm tra xem "playlist" có tồn tại trong JSON không
        if (!j.contains("playlist") || !j["playlist"].is_object()) {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }

        // Kiểm tra xem playlist với tên `playlistName` có tồn tại không
        if (!j["playlist"].contains(playlistName)) {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }

        // Thêm file path (command) vào playlist
        // Kiểm tra nếu file path chưa tồn tại trong playlist
        auto& playlistFiles = j["playlist"][playlistName];
        if (std::find(playlistFiles.begin(), playlistFiles.end(), command) == playlistFiles.end()) {
            playlistFiles.push_back(command);  // Thêm vào playlist
        } else {
            data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
            return;
        }

        // Lưu lại file JSON với dữ liệu mới
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << j.dump(4);  // Ghi lại dữ liệu JSON vào file (indent 4 cho dễ đọc)
            outFile.close();

        } else {
        }

        // Tải dữ liệu playlist từ file
        sharedControllerFunction::loadMediaFileLib(data, filename);
        sharedControllerFunction::loadMediaFileToPlaylist(filename);
        sharedControllerFunction::loadPlaylist(data, filename);
        sharedControllerFunction::loadSelectedPlaylist(data);
        sharedControllerFunction::loadCurrentPlaylist(data);
        // Cập nhật chế độ điều khiển trong appData
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
    }
}

void playlistManagerController::deletePlaylist(appData& data, std::string& filename) {
    // Lấy playlist đã chọn
    playlist pl = data.getSelectedPlaylist();
    std::string playlistName = pl.getPlaylistName();

    // Đọc file JSON
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        return;
    }

    json j;
    try {
        inFile >> j;
    } catch (const std::exception& e) {
        inFile.close();
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        return;
    }
    inFile.close();

    // Kiểm tra hợp lệ của dữ liệu JSON
    if (!j.contains("playlist") || !j["playlist"].is_object()) {
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        return;
    }

    if (!j["playlist"].contains(playlistName)) {
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        return;
    }

    // Xóa playlist
    j["playlist"].erase(playlistName);
    // Ghi lại file
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        data.setControlMode(PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN);
        return;
    }

    try {
        outFile << j.dump(4);  // Ghi JSON với indent 4
    } catch (const std::exception& e) {
    }
    outFile.close();

    // Reset playlist đã chọn
    data.setSelectedPlaylist(playlist());

    // Tải lại dữ liệu playlist
    sharedControllerFunction::loadPlaylist(data, filename);
    sharedControllerFunction::loadSelectedPlaylist(data);
    sharedControllerFunction::loadCurrentPlaylist(data);

    // Cập nhật trạng thái giao diện
    data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
}