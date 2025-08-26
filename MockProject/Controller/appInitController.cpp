#include "appInitController.h"

void appInitController::appInitFunction(appData& data, std::string& filename){
    sharedControllerFunction::loadMediaFileLib(data, filename);
    sharedControllerFunction::loadMediaFileToPlaylist(filename);
    sharedControllerFunction::loadPlaylist(data, filename);
    data.setControlMode(MAIN_SCREEN);
}