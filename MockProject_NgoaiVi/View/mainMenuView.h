#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <iostream>
#include <vector>
#include <string>
#include "../Model/applicationData.h"
#include "sharedViewFunction.h"

class mainMenuView {
    public:
        static void mainMenu(appData& data);
        static void mainMenuOption();
};

#endif