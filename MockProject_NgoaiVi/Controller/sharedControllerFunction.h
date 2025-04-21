#ifndef SHAREDCONTROLLERFUNCTION_H
#define SHAREDCONTROLLERFUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Model/applicationData.h"

using json = nlohmann::json;

class sharedControllerFunction {
    public:
        static void loadPlaylist(appData& data, std::string& filename);
        static void loadMediaFileLib(appData& data, std::string& filename);
        static void loadSelectedPlaylist(appData& data);
        static void loadCurrentPlaylist(appData& data);
        static void loadMediaFileToPlaylist(std::string& filename);
        static void loadSelectedMediaFile(appData& data);
        static void loadCurrentMediaFile(appData& data);
};

#endif