#include "applicationData.h"

//Getter
std::vector<playlist> appData::getPlaylistList(){
    return playlistList;
}

std::vector<mediaFile> appData::getMediaLibrary(){
    return mediaLib;
}

mediaFile appData::getCurrentMediaFile(){
    return currentMediaFile;
}

playlist appData::getCurrentPlaylist(){
    return currentPlaylist;
}

int appData::getMediaFileIndex(){
    return mediaFileIndex;
}

bool appData::isPlaying(){
    return isPlayingStatus;
}

controlMode appData::getControlMode(){
    return mode;
}

double appData::getVolumn(){
    return volumn;
}

int appData::getNumberOfCurrentLines(){
    return numberOfCurrentLines;
}

playlist appData::getSelectedPlaylist(){
    return selectedPlaylist;
}

mediaFile appData::getSelectedMediaFile(){
    return selectedMediaFile;
}

bool appData::getBoardConnectStatus(){
    return isBoardConnectedStatus;
}

//Setter
void appData::setPlaylistList(std::vector<playlist> newPlaylistList){
    this->playlistList = newPlaylistList;
}

void appData::setMediaLibrary(std::vector<mediaFile> newMediaLib){
    this->mediaLib = newMediaLib;
}

void appData::setCurrentMediaFile(mediaFile newMediaFile){
    this->currentMediaFile = newMediaFile;
}

void appData::setCurrentPlaylist(playlist newPlaylist){
    this->currentPlaylist = newPlaylist;
}

void appData::setMediaFileIndex(int newIndex){
        this->mediaFileIndex = newIndex;
}

void appData::setIsPlayingStatus(int newStatus){
    this->isPlayingStatus = newStatus;
}

void appData::setControlMode(controlMode newMode){
    this->mode = newMode;
}

void appData::setVolumn(double newVolumn){
    this->volumn = newVolumn;
}

void appData::setNumberOfCurrentLines(int num){
    this->numberOfCurrentLines = num;
}

void appData::setSelectedPlaylist(playlist pl){
    this->selectedPlaylist = pl;
}

void appData::setSelectedMediaFile(mediaFile mf){
    this->selectedMediaFile = mf;
}

void appData::setIsBoardConnectStatus(bool isConnected){
    this->isBoardConnectedStatus = isConnected;
}