#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Model/applicationData.h"
#include "sharedControllerFunction.h"
#include "musicPlayController.h"
#include "mediaFileLibController.h"

using json = nlohmann::json;

class playlistManagerController {
    public:
        static void generalPlaylistController(std::string command, appData& data);
        static void selectPlaylistController(std::string command, appData& data);
        static void selectedPlaylistController(std::string command, appData& data);
        static void createPLaylistController(std::string& filename, std::string command, appData& data);
        static void addMediaFileToPlaylist(std::string command, appData& data, std::string& filename);
        static void playPLaylist(appData& data);
        static void deletePlaylist(appData& data, std::string& filename);
};

#endif