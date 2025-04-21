#ifndef MEDIAFILEMANAGERVIEW_H
#define MEDIAFILEMANAGERVIEW_H

#include "sharedViewFunction.h"
#include <iostream>
#include <vector>
#include <string>
#include "../Model/applicationData.h"

class mediaFileManagerView {
    public:
        static void mainView(appData& data);
        static void displayMainViewOption();
        static void addNewFilePathView(appData& data);
        static void browseDirectoryView(appData& data);
        static void selectMediaFileView(appData& data);
};

#endif