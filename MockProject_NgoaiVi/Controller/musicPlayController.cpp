#include "musicPlayController.h"

void musicPlayController::mainScreenController(std::string command, appData& data){
    if (command == "p") {
        musicPlayController::pauseOrResume(data);
    } else if (command == "n") {
        musicPlayController::nextTrack(data);
    } else if (command == "b") {
        musicPlayController::previousTrack(data);
    } else if (command == "q") {
        data.setControlMode(MAIN_SCREEN);
    } else if (command == "v") {
        data.setControlMode(MUSIC_PLAY_VOLUMN_SCREEN);
    } else if (command == "1") { // Bước vào
        if (!Mix_PlayingMusic()) {
            musicPlayController::playMusic(data);
        }
    }
}

void musicPlayController::playMusic(appData& data){
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        return;
    }

    if (data.getCurrentPlaylist().getPlaylistMediaFile().empty()) {
        return;
    }

    if (data.getMediaFileIndex() >= static_cast<int>(data.getCurrentPlaylist().getPlaylistMediaFile().size())) {
        return;
    }

    mediaFile currentMedia = data.getCurrentPlaylist().getPlaylistMediaFile()[data.getMediaFileIndex()];
    Mix_Music* music = Mix_LoadMUS(currentMedia.getFilePath().c_str());
    if (!music) {
        return;
    }

    Mix_PlayMusic(music, 1);
    Mix_VolumeMusic(data.getVolumn());
    data.setCurrentMediaFile(currentMedia);
    data.setIsPlayingStatus(true);
}

void musicPlayController::pauseOrResume(appData& data){
    if (Mix_PlayingMusic()) {
        if (Mix_PausedMusic()) {
            Mix_ResumeMusic();
            data.setIsPlayingStatus(true);
        } else {
            Mix_PauseMusic();
            data.setIsPlayingStatus(false);
        }
    }
}

void musicPlayController::stopMusic(appData& data){
    Mix_HaltMusic();
    data.setIsPlayingStatus(false);
}

void musicPlayController::nextTrack(appData& data){
    if (data.getMediaFileIndex() < static_cast<int>(data.getCurrentPlaylist().getPlaylistMediaFile().size()) - 1) {
        data.setMediaFileIndex(data.getMediaFileIndex() + 1);
        musicPlayController::playMusic(data);
    } else {
        data.setMediaFileIndex(0);
        musicPlayController::playMusic(data);
    }
}

void musicPlayController::previousTrack(appData& data) {
    if (data.getMediaFileIndex() > 0) {
        data.setMediaFileIndex(data.getMediaFileIndex() - 1);
        musicPlayController::playMusic(data);
    } else {
        data.setMediaFileIndex(static_cast<int>(data.getCurrentPlaylist().getPlaylistMediaFile().size()) - 1);
        musicPlayController::playMusic(data);
    }
}

void musicPlayController::setVolumn(std::string command, appData& data) {
    double volumn;
    try
    {
        volumn = std::stod(command);
        if(volumn < 0)
        volumn = 0;
        if(volumn > 128)
            volumn = 128;
        data.setVolumn(volumn);
        Mix_VolumeMusic(data.getVolumn());
        data.setControlMode(MUSIC_PLAY_MAIN_SCREEN);
    }
    catch (const std::invalid_argument& e){
        volumn = data.getVolumn();
    }
}

void musicPlayController::uartSetVolumn(std::string command, appData& data) {
    double volumn;
    try
    {
        volumn = std::stod(command);
        if(volumn < 0)
        volumn = 0;
        if(volumn > 128)
            volumn = 128;
        data.setVolumn(volumn);
        Mix_VolumeMusic(data.getVolumn());
    }
    catch (const std::invalid_argument& e){
        volumn = data.getVolumn();
    }
}