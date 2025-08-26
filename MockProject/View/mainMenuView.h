#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <iostream>
#include <vector>
#include <string>
#include "/home/quangha/PhamQuangHa/Code/MockProject/Model/applicationData.h"
#include "sharedViewFunction.h"

class mainMenuView {
    public:
        static void mainMenu(appData& data);
        static void mainMenuOption();
};

#endif