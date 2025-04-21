#include "musicPlayView.h"

void musicPlayView::displayPlayMusicOptionView(){
    std::cout << "Enter: p (pause/resume), n (next), b (previous), v (set volumn), q (quit to main manu)\n";
}

void musicPlayView::playMusicView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayPlaylistMediaFile(data.getCurrentPlaylist());
    std::cout << std::endl;
    sharedViewFunction::displayCurrentTrack(data);
    std::cout << std::endl;
    musicPlayView::displayPlayMusicOptionView();
}

void musicPlayView::setVolumnView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayPlaylistMediaFile(data.getCurrentPlaylist());
    std::cout << std::endl;
    sharedViewFunction::displayCurrentTrack(data);
    std::cout << std::endl;
    std::cout << "Enter Volumn (Range 0~128): " << std::endl;
}

