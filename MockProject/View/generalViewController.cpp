#include "generalViewController.h"

void generalViewController::viewDo(appData& data){
    if(data.getControlMode() == MAIN_SCREEN){
        mainMenuView::mainMenu(data);
    }
    else if(data.getControlMode() >= MUSIC_PLAY_MAIN_SCREEN && data.getControlMode() <= MUSIC_PLAY_VOLUMN_SCREEN){
        generalViewController::musicPlayManagerView(data);
    }
    else if(data.getControlMode() >= PLAYLIST_MANAGER_MAIN_SCREEN && data.getControlMode() <= PlAYLIST_MANAGER_PLAY_PLAYLIST){
        generalViewController::playlistManagerView(data);
    }
    else if(data.getControlMode() >= MEDIA_FILE_MAIN_SCREEN && data.getControlMode() <= MEDIA_FILE_SELECT_MEDIA_FILE){
        generalViewController::mediaFileManagerView(data);
    }
    else if(data.getControlMode() >= EDIT_MEDIA_FILE_MAIN_SCREEN && data.getControlMode() <= EDIT_MEDIA_FILE_ADD_TO_PLAYLIST){
        generalViewController::mediaFileEditView(data);
    }
}

void generalViewController::mainMenuView(appData& data){
    if(data.getControlMode() == MAIN_SCREEN){
        mainMenuView::mainMenu(data);
    }
}

void generalViewController::musicPlayManagerView(appData& data){
    if(data.getControlMode() == MUSIC_PLAY_MAIN_SCREEN){
        musicPlayView::playMusicView(data);
    }
    else if(data.getControlMode() == MUSIC_PLAY_VOLUMN_SCREEN){
       musicPlayView::setVolumnView(data);
    }
}

void generalViewController::mediaFileManagerView(appData& data){
    if(data.getControlMode() == MEDIA_FILE_MAIN_SCREEN){
        mediaFileManagerView::mainView(data);      
    }
    else if(data.getControlMode() == MEDIA_FILE_ADD_NEW_FILE){
        mediaFileManagerView::addNewFilePathView(data);
    }
    else if(data.getControlMode() == MEDIA_FILE_BROWSE_DIRECTORY){
        mediaFileManagerView::browseDirectoryView(data);
    }
    else if(data.getControlMode() == MEDIA_FILE_SELECT_MEDIA_FILE){
        mediaFileManagerView::selectMediaFileView(data);
    }
}

void generalViewController::playlistManagerView(appData& data){
    if(data.getControlMode() == PLAYLIST_MANAGER_MAIN_SCREEN){
        playlistView::playlistManagerMainView(data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_PLAYLIST_SELECT_SCREEN){
        playlistView::playlistSelectView(data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_PLAYLIST_EDIT_SCREEN){
        playlistView::playlistSelectedView(data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_CREATE_NEW_PLAYLIST_SCREEN){
        playlistView::playlistCreateNewPlaylistView(data);
    }
    else if(data.getControlMode() == PLAYLIST_MANAGER_ADD_MEDIA_TO_PLAYLIST_SCREEN){
        playlistView::playlistAddMediaFileToPlaylist(data);
    }
}

void generalViewController::mediaFileEditView(appData& data){
    if(data.getControlMode() == EDIT_MEDIA_FILE_MAIN_SCREEN){
        mediaFileEditView::mainView(data);
    }
    else if(data.getControlMode() >= EDIT_MEDIA_FILE_EDIT_TITLE && data.getControlMode() <= EDIT_MEDIA_FILE_EDIT_GENRE){
        mediaFileEditView::editMetadataView(data);
    }
    else if(data.getControlMode() == EDIT_MEDIA_FILE_ADD_TO_PLAYLIST){
        mediaFileEditView::addMediaFileToPlaylist(data);
    }
}