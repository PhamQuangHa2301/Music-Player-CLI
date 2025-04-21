#ifndef GENERALCONTROLLER_H
#define GENERALCONTROLLER_H

#include <iostream>
#include <string>
#include "../Model/applicationData.h"
#include "musicPlayController.h"
#include "playlistController.h"
#include "appInitController.h"
#include "mediaFileLibController.h"
#include "mainMenuController.h" 
#include "mediaFileEditController.h"

class generalController {
    public: 
        static void controllerDo(std::string filename, std::string command, appData& data);

        static void initAppController(std::string filename, appData& data);
        static void mainMenuController(std::string command, appData& data);
        static void musicPlayController(std::string command, appData& data);
        static void playlistManagerController(std::string filename, std::string command, appData& data);
        static void mediaFileLibraryController(std::string filename, std::string command, appData& data);
        static void mediaFileEditController(std::string filename, std::string command, appData& data);
};

#endif