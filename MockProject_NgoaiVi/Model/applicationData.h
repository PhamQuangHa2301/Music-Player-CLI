#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <iostream>
#include <string>
#include <vector>
#include "mediaFile.h"
#include "playlist.h"

enum controlMode {
    INIT_PROGRAM,

    QUIT_PROGRAM,

    MAIN_SCREEN,

    MUSIC_PLAY_MAIN_SCREEN,
    MUSIC_PLAY_VOLUMN_SCREEN,

    PLAYLIST_MANAGER_MAIN_SCREEN,
    PLAYLIST_MANAGER_PLAYLIST_SELECT_SCREEN,
    PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN,
    PLAYLIST_MANAGER_CREATE_NEW_PLAYLIST_SCREEN,
    PLAYLIST_MANAGER_ADD_MEDIA_TO_PLAYLIST_SCREEN,
    PlAYLIST_MANAGER_PLAY_PLAYLIST,
    PLAYLIST_MANAGER_DELETE_PLAYLIST,

    MEDIA_FILE_MAIN_SCREEN,
    MEDIA_FILE_ADD_NEW_FILE,
    MEDIA_FILE_BROWSE_DIRECTORY,
    MEDIA_FILE_SELECT_MEDIA_FILE,

    EDIT_MEDIA_FILE_MAIN_SCREEN,
    EDIT_MEDIA_FILE_PLAY,
    EDIT_MEDIA_FILE_EDIT_TITLE,
    EDIT_MEDIA_FILE_EDIT_ARTIST,
    EDIT_MEDIA_FILE_EDIT_ALBUM,
    EDIT_MEDIA_FILE_EDIT_GENRE,
    EDIT_MEDIA_FILE_ADD_TO_PLAYLIST
};

class appData {
    private:
        //Application Data
        std::vector<playlist> playlistList;
        std::vector<mediaFile> mediaLib;
        bool isBoardConnectedStatus;
        //Current Play
        mediaFile currentMediaFile;
        playlist currentPlaylist;
        int mediaFileIndex;
        bool isPlayingStatus;
        controlMode mode;
        double volumn;
        int numberOfCurrentLines;
        //Selected Object to edit
        playlist selectedPlaylist;
        mediaFile selectedMediaFile;

    public:
        //Constructer
        appData() : isBoardConnectedStatus(false), mediaFileIndex(0), isPlayingStatus(false), mode(INIT_PROGRAM), volumn(128), numberOfCurrentLines(0){};
        ~appData(){};

        //Getter
        std::vector<playlist> getPlaylistList();
        std::vector<mediaFile> getMediaLibrary();

        mediaFile getCurrentMediaFile();
        playlist getCurrentPlaylist();
        int getMediaFileIndex();
        bool isPlaying();
        controlMode getControlMode();
        double getVolumn();
        int getNumberOfCurrentLines();

        playlist getSelectedPlaylist();
        mediaFile getSelectedMediaFile();
        bool getBoardConnectStatus();

        //Setter
        void setPlaylistList(std::vector<playlist> newPlaylist);
        void setMediaLibrary(std::vector<mediaFile> newMediaLib);

        void setCurrentMediaFile(mediaFile newMediaFile);
        void setCurrentPlaylist(playlist newPlaylist);
        void setMediaFileIndex(int newIndex);
        void setIsPlayingStatus(int newStatus);
        void setControlMode(controlMode newMode);
        void setVolumn(double newVolumn);
        void setNumberOfCurrentLines(int num);

        void setSelectedPlaylist(playlist pl);
        void setSelectedMediaFile(mediaFile mf);
        void setIsBoardConnectStatus(bool isConnect);
};

#endif