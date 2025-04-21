#include "mainMenuView.h"

void mainMenuView::mainMenuOption(){
    std::cout << "Select Option" << std::endl;
    std::cout << "[1]. Play Music Controller" << std:: endl;
    std::cout << "[2]. Playlist Manager" << std::endl;
    std::cout << "[3]. Media File Manager" << std::endl;
    std::cout << "[q]. To Quit Program" << std::endl;
}

void mainMenuView::mainMenu(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayCurrentTrack(data);
    std::cout << std::endl;
    mainMenuView::mainMenuOption();
}