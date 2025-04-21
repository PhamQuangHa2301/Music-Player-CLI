#ifndef GENERALVIEWCONTROLLER_H
#define GENERALVIEWCONTROLLER_H

#include "../Model/applicationData.h"
#include "musicPlayView.h"
#include "playlistView.h"
#include "mediaFileManagerView.h"
#include "mainMenuView.h"
#include "mediaFileEditView.h"

class generalViewController {
    public:
        static void viewDo(appData& data);
        static void mainMenuView(appData& data);
        static void musicPlayManagerView(appData& data);
        static void playlistManagerView(appData& data);
        static void mediaFileManagerView(appData& data);
        static void mediaFileEditView(appData& data);
};

#endif