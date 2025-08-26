#ifndef SHAREDVIEWFUNCTION_H
#define SHAREDVIEWFUNCTION_H

#include <iostream>
#include "/home/quangha/PhamQuangHa/Code/MockProject/Model/applicationData.h"

class sharedViewFunction {
    public:
        static void displayPlaylistMediaFile(playlist pl);
        static void displayMediaFile(mediaFile mediaFile);
        static void displayCurrentTrack(appData& data);
        static void displayCurrentPlaylist(appData& data);
        static void displayMediaLibrary(appData& data);
        static void displaySelectedMediaFile(appData& data);
};

#endif