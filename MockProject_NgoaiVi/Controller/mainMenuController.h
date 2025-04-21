#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include <iostream>
#include <string>
#include "../Model/applicationData.h"

class mainMenuController {
    public:
        static void mainScreenController(std::string command, appData& data);
};

#endif