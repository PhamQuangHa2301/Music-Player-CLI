#include <iostream>
#include <fstream>
#include <dirent.h>
#include <nlohmann/json.hpp>
#include <unistd.h>
#include "Model/applicationData.h"
#include "Controller/generalController.h"
#include "View/generalViewController.h"

int main() {
    std::string filename = "log.json";
    appData data;
    std::string command;
    generalController::controllerDo(filename, command, data);
    generalViewController::viewDo(data);
    
    while (data.getControlMode() != QUIT_PROGRAM) {
        std::getline(std::cin, command);
        generalController::controllerDo(filename, command, data);
        generalViewController::viewDo(data);
    }
    return 0;
}