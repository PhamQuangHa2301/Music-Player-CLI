#ifndef MEDIAFILEEDITCONTROLLER_H
#define MEDIAFILEEDITCONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Model/applicationData.h"
#include "sharedControllerFunction.h"
#include "musicPlayController.h"

class mediaFileEditController {
    public:
        static void mainMenuOption(std::string command, appData& data);
        static void mediaFilePlay(appData& data);
        static void editMediaFile(std::string command, std::string filename, appData& data);
        static void addToPlaylist(std::string command, std::string filename, appData& data);
};

#endif