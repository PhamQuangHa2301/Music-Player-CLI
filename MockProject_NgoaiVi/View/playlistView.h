#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../Model/applicationData.h"
#include "sharedViewFunction.h"

class playlistView {
    public:
        static void displayAllPlaylist(appData& data);
        static void displayPlaylistOption();
        static void playlistSelectView(appData& data);
        static void playlistSelectedView(appData& data);
        static void playlistManagerMainView(appData& data);
        static void playlistCreateNewPlaylistView(appData& data);
        static void playlistAddMediaFileToPlaylist(appData& data);
};

#endif