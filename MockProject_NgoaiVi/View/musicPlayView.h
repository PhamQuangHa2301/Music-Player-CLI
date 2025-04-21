#ifndef MUSICPLAYVIEW_H
#define MUSICPLAYVIEW_H

#include "sharedViewFunction.h"
#include "../Model/applicationData.h"

class musicPlayView {
    public:
        static void displayPlayMusicOptionView();
        static void setVolumnView(appData& data);
        static void playMusicView(appData& data);
};

#endif