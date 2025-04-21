#include "playlistView.h"

void playlistView::displayAllPlaylist(appData& data){
    std::vector<playlist> list = data.getPlaylistList();
    std::cout << "List of Playlist: " << std::endl;
    if(static_cast<int>(list.size()) == 0){
        std::cout << "There is no Playlist." << std::endl;
    }
    else {
        for(int i = 0; i < static_cast<int>(list.size()); i++){
            std::cout << i+1 << ". " << list[i].getPlaylistName() << "." << std::endl;
        }
    }
}

void playlistView::displayPlaylistOption(){
    std::cout << "Enter: c (create new playlist), s (select playlist), q (quit to main menu)." << std::endl;
}

void playlistView::playlistSelectView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    std::vector<playlist> list = data.getPlaylistList();
    std::cout << "List of Playlist: " << std::endl;
    if(static_cast<int>(list.size()) == 0){
        std::cout << "There is no Playlist." << std::endl;
        std::cout << "Enter q (quit)" << std::endl;
        return;
    }
    else {
        for(int i = 0; i < static_cast<int>(list.size()); i++){
            std::cout << i+1 << ". " << list[i].getPlaylistName() << "." << std::endl;
        }
    }
    std::cout << "Enter Number In Range (1 ~ " << static_cast<int>(data.getPlaylistList().size()) << ") to Select, q (quit): " << std::endl;
}

void playlistView::playlistManagerMainView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    playlistView::displayAllPlaylist(data);
    std::cout << std::endl;
    playlistView::displayPlaylistOption();
}

void playlistView::playlistSelectedView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    std::cout << "Playlist Name: " << data.getSelectedPlaylist().getPlaylistName() << std::endl;
    sharedViewFunction::displayPlaylistMediaFile(data.getSelectedPlaylist());
    std::cout << "Enter:a (add new media file),d (delete playlist), p (play playlist), q (quit):" << std::endl;
}

void playlistView::playlistCreateNewPlaylistView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    playlistView::displayAllPlaylist(data);
    std::cout << std::endl;
    std::cout << "Enter New Playlist Name: " << std::endl;
}

void playlistView::playlistAddMediaFileToPlaylist(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    std::cout << "Playlist Name: " << data.getSelectedPlaylist().getPlaylistName() << std::endl;
    sharedViewFunction::displayPlaylistMediaFile(data.getSelectedPlaylist());
    std::cout << "Enter Media File Path (q to quit): " << std::endl;
}