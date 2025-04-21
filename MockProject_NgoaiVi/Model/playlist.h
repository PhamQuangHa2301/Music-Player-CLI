#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "mediaFile.h"

class playlist {
    private:
        std::string playlistName;
        std::vector<mediaFile> List;
    public:
        //Constructor
        playlist(){};
        playlist(std::string playlistName);
        ~playlist(){};

        void addMediaFile(mediaFile newFile);
        void removeMediaFile(int fileIndex);
        //Getter
        std::string getPlaylistName();
        std::vector<mediaFile> getPlaylistMediaFile();

        //Setter
        void setPlaylistName(std::string newPlaylistName);
};

#endif