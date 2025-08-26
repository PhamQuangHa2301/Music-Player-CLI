#include "playlist.h"

playlist::playlist(std::string playlistName) : playlistName(playlistName){}

void playlist::addMediaFile(mediaFile newFile) {
    List.push_back(newFile);
}

void playlist::removeMediaFile(int fileIndex) {
    List.erase(List.begin() + fileIndex);
}

std::string playlist::getPlaylistName(){
    return playlistName;
}

std::vector<mediaFile> playlist::getPlaylistMediaFile(){
    return List;
}

void playlist::setPlaylistName(std::string newPlaylistName){
    this->playlistName = newPlaylistName;
}