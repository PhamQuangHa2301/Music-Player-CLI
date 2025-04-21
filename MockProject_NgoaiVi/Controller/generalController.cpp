#include "generalController.h"

void generalController::controllerDo(std::string filename, std::string command, appData& data){
    if(data.getControlMode() == INIT_PROGRAM){
        generalController::initAppController(filename, data);
    }
    else if(data.getControlMode() == MAIN_SCREEN){
        generalController::mainMenuController(command, data);
    }
    else if(data.getControlMode() >= MUSIC_PLAY_MAIN_SCREEN && data.getControlMode() <= MUSIC_PLAY_VOLUMN_SCREEN){
        generalController::musicPlayController(command, data);
    }
    else if(data.getControlMode() >= PLAYLIST_MANAGER_MAIN_SCREEN && data.getControlMode() <= PLAYLIST_MANAGER_DELETE_PLAYLIST){
        generalController::playlistManagerController(filename, command, data);
    }
    else if(data.getControlMode() >= MEDIA_FILE_MAIN_SCREEN && data.getControlMode() <= MEDIA_FILE_SELECT_MEDIA_FILE){
        generalController::mediaFileLibraryController(filename, command, data);
    }
    else if(data.getControlMode() >= EDIT_MEDIA_FILE_MAIN_SCREEN && data.getControlMode() <= EDIT_MEDIA_FILE_ADD_TO_PLAYLIST){
        generalController::mediaFileEditController(filename, command, data);
    }
}

void generalController::initAppController(std::string filename, appData& data){
    if(data.getControlMode() == INIT_PROGRAM){
        appInitController::appInitFunction(data, filename);
    }
}

void generalController::mainMenuController(std::string command, appData& data){
    if(data.getControlMode() == MAIN_SCREEN){
        mainMenuController::mainScreenController(command, data);
    }   
}

void generalController::musicPlayController(std::string command, appData& data){
    if(data.getControlMode() == MUSIC_PLAY_MAIN_SCREEN){
        musicPlayController::mainScreenController(command, data);
    }
    else if(data.getControlMode() == MUSIC_PLAY_VOLUMN_SCREEN){
        musicPlayController::setVolumn(command, data);
    }
}

void generalController::playlistManagerController(std::string filename, std::string command, appData& data){
    if(data.getControlMode() == PLAYLIST_MANAGER_MAIN_SCREEN){
        playlistManagerController::generalPlaylistController(command, data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_PLAYLIST_SELECT_SCREEN){
        playlistManagerController::selectPlaylistController(command, data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN){
        playlistManagerController::selectedPlaylistController(command, data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_CREATE_NEW_PLAYLIST_SCREEN){
        playlistManagerController::createPLaylistController(filename, command, data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_ADD_MEDIA_TO_PLAYLIST_SCREEN){
        playlistManagerController::addMediaFileToPlaylist(command, data, filename);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_DELETE_PLAYLIST){
        playlistManagerController::deletePlaylist(data, filename);
    }
    else if(data.getControlMode() == PlAYLIST_MANAGER_PLAY_PLAYLIST){
        playlistManagerController::playPLaylist(data);
    }
}

void generalController::mediaFileLibraryController(std::string filename, std::string command, appData& data){
    if(data.getControlMode() == MEDIA_FILE_MAIN_SCREEN){
        mediaFileLibController::mainScreenController(command, data);
    }
    else if(data.getControlMode() == MEDIA_FILE_ADD_NEW_FILE){
        mediaFileLibController::addNewFilePath(command, data, filename);
    }
    else if(data.getControlMode() == MEDIA_FILE_BROWSE_DIRECTORY){
        mediaFileLibController::browseDirectory(command, data, filename);
    }
    else if(data.getControlMode() == MEDIA_FILE_SELECT_MEDIA_FILE){
        mediaFileLibController::selectMediaFile(command, data);
    }
}

void generalController::mediaFileEditController(std::string filename, std::string command, appData& data){
    if(data.getControlMode() == EDIT_MEDIA_FILE_MAIN_SCREEN){
        mediaFileEditController::mainMenuOption(command, data);
    }
    else if(data.getControlMode() == EDIT_MEDIA_FILE_PLAY){
        mediaFileEditController::mediaFilePlay(data);
    }
    else if(data.getControlMode() >= EDIT_MEDIA_FILE_EDIT_TITLE && data.getControlMode() <= EDIT_MEDIA_FILE_EDIT_GENRE){
        mediaFileEditController::editMediaFile(command, filename, data);
    }
    else if(data.getControlMode() == EDIT_MEDIA_FILE_ADD_TO_PLAYLIST){
        mediaFileEditController::addToPlaylist(command, filename, data);
    }
}