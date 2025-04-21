#ifndef MEDIAFILELIBCONTROLLER_H
#define MEDIAFILELIBCONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Model/applicationData.h"
#include "sharedControllerFunction.h"

class mediaFileLibController {
    public:
        static void mainScreenController(std::string command, appData& data);
        static void addNewFilePath(std::string command, appData& data, std::string filename);
        static void browseDirectory(std::string command, appData& data, std::string filename);
        static void selectMediaFile(std::string command, appData& data);
};

#endif