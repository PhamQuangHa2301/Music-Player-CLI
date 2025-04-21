#include "mainMenuController.h"

void mainMenuController::mainScreenController(std::string command, appData& data){
    if(command == "1"){
        data.setControlMode(MUSIC_PLAY_MAIN_SCREEN);
    }
    else if(command == "2"){
        data.setControlMode(PLAYLIST_MANAGER_MAIN_SCREEN);
    }
    else if(command == "3"){
        data.setControlMode(MEDIA_FILE_MAIN_SCREEN);
    }
    else if (command == "q"){
        data.setControlMode(QUIT_PROGRAM);
    }
}