#ifndef SHAREDVIEWFUNCTION_H
#define SHAREDVIEWFUNCTION_H

#include <iostream>
#include "../Model/applicationData.h"

class sharedViewFunction {
    public:
        static void displayPlaylistMediaFile(playlist pl);
        static void displayMediaFile(mediaFile mediaFile);
        static void displayCurrentTrack(appData& data);
        static void displayCurrentPlaylist(appData& data);
        static void displayMediaLibrary(appData& data);
        static void displayBoardStatusAndVolumn(appData& data);
};

#endif