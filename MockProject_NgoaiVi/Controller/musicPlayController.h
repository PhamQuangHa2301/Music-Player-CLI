#ifndef MUSICPLAYERCONTROLLER_H
#define MUSICPLAYERCONTROLLER_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "../Model/applicationData.h"

class musicPlayController {
    public:
        static void mainScreenController(std::string command, appData& data);
        static void playMusic(appData& data);
        static void pauseOrResume(appData& data);
        static void stopMusic(appData& data);
        static void nextTrack(appData& data);
        static void previousTrack(appData& data);
        static void setVolumn(std::string command, appData& data);
        static void uartSetVolumn(std::string command, appData& data);
};

#endif