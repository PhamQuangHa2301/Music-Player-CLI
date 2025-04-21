#ifndef APPINITCONTROLLER_H
#define APPINITCONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "/home/quangha/PhamQuangHa/Code/MockProject_NgoaiVi/Model/applicationData.h"
#include "sharedControllerFunction.h"

using json = nlohmann::json;

class appInitController {
    public: 
        static void appInitFunction(appData& data, std::string& filename);
};

#endif