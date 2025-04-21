#ifndef MEDIAFILEEDITVIEW_H
#define MEDIAFILEEDITVIEW_H

#include "sharedViewFunction.h"
#include <iostream>
#include <vector>
#include <string>
#include "../Model/applicationData.h"

class mediaFileEditView {
    public:
        static void mainView(appData& data);
        static void mainMenuOption();
        static void editMetadataView(appData& data);
        static void addMediaFileToPlaylist(appData& data);
};

#endif