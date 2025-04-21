#include "mediaFileEditController.h"

void mediaFileEditController::mainMenuOption(std::string command, appData& data){
    if(command == "q"){
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    }
    else if(command == "p"){
        data.setControlMode(EDIT_MEDIA_FILE_PLAY);
    }
    else if(command == "1"){
        data.setControlMode(EDIT_MEDIA_FILE_EDIT_TITLE);
    }
    else if(command == "2"){
        data.setControlMode(EDIT_MEDIA_FILE_EDIT_ARTIST);
    }
    else if(command == "3"){
        data.setControlMode(EDIT_MEDIA_FILE_EDIT_ALBUM);
    }
    else if(command == "4"){
        data.setControlMode(EDIT_MEDIA_FILE_EDIT_GENRE);
    }
    else if(command == "a"){
        data.setControlMode(EDIT_MEDIA_FILE_ADD_TO_PLAYLIST);
    }
}

void mediaFileEditController::mediaFilePlay(appData& data){
    for(int i = 0; i < static_cast<int>(data.getPlaylistList().size()); i++){
        if(data.getPlaylistList()[i].getPlaylistName() == "mediaFile"){
            data.setCurrentPlaylist(data.getPlaylistList()[i]);
        }
    }

    for(int i = 0; i < static_cast<int>(data.getCurrentPlaylist().getPlaylistMediaFile().size()); i++){
        if(data.getCurrentPlaylist().getPlaylistMediaFile()[i].getFilePath() == data.getSelectedMediaFile().getFilePath()){
            data.setMediaFileIndex(i);
        }
    }

    data.setCurrentMediaFile(data.getSelectedMediaFile());
    musicPlayController::playMusic(data);
    data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
}

void mediaFileEditController::editMediaFile(std::string command, std::string filename, appData& data){
    std::string newData = command;
    mediaFile selectedMediaFile = data.getSelectedMediaFile();  
    metadata curMetadata = selectedMediaFile.getMetadata();
    switch(data.getControlMode()){
        case EDIT_MEDIA_FILE_EDIT_ARTIST:
            curMetadata.setArtist(newData);        
            break;
        case EDIT_MEDIA_FILE_EDIT_ALBUM:
            curMetadata.setAlbum(newData);
            break;
        case EDIT_MEDIA_FILE_EDIT_TITLE:
            curMetadata.setTitle(newData);
            break;
        case EDIT_MEDIA_FILE_EDIT_GENRE:
            curMetadata.setGenre(newData);
            break;
        default:
            break;
    }

    sharedControllerFunction::loadMediaFileLib(data, filename);
    sharedControllerFunction::loadPlaylist(data, filename);
    sharedControllerFunction::loadCurrentPlaylist(data);
    sharedControllerFunction::loadSelectedPlaylist(data);
    sharedControllerFunction::loadSelectedMediaFile(data);
    sharedControllerFunction::loadCurrentMediaFile(data);
    data.setControlMode(EDIT_MEDIA_FILE_MAIN_SCREEN);
}

void mediaFileEditController::addToPlaylist(std::string command, std::string filename, appData& data) {
    if (command == "q") {
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
        return;
    }
    try {
        int index = std::stoi(command);
        if (index < 1 || index > static_cast<int>(data.getPlaylistList().size())) {
        }

        index--; // chuyển về index bắt đầu từ 0
        std::string playlistName = data.getPlaylistList()[index].getPlaylistName();
        std::string mediaPath = data.getSelectedMediaFile().getFilePath();

        // 1. Đọc JSON từ file
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            return;
        }

        json jsonData;
        inputFile >> jsonData;
        inputFile.close();

        // 2. Kiểm tra và thêm mediaPath vào playlist tương ứng
        json& playlists = jsonData["playlist"];

        // Nếu playlist chưa tồn tại, tạo mới
        if (!playlists.contains(playlistName)) {
            playlists[playlistName] = json::array();
        }

        // Kiểm tra trùng lặp
        auto& array = playlists[playlistName];
        if (std::find(array.begin(), array.end(), mediaPath) == array.end()) {
            array.push_back(mediaPath);
        }

        // 3. Ghi lại file
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            return;
        }
        outputFile << jsonData.dump(4); // indent 4 cho đẹp
        outputFile.close();

        sharedControllerFunction::loadMediaFileLib(data, filename);
        sharedControllerFunction::loadPlaylist(data, filename);
        sharedControllerFunction::loadCurrentPlaylist(data);
        sharedControllerFunction::loadSelectedPlaylist(data);
        sharedControllerFunction::loadSelectedMediaFile(data);
        sharedControllerFunction::loadCurrentMediaFile(data);
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    } 
    catch (const std::invalid_argument&) {
    } 
    catch (const std::out_of_range&) {
    }
}