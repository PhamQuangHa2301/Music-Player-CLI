#include "mediaFileEditView.h"

void mediaFileEditView::mainView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    mediaFile selectedMediaFile = data.getSelectedMediaFile();
    std::cout << "Edit Media File: " << std::endl;
    std::cout << "     File Name: " << selectedMediaFile.getfileName() << "." << std::endl;
    std::cout << "[1]. Title: " << selectedMediaFile.getMetadata().getTitle() << "." << std::endl;
    std::cout << "[2]. Artist: " << selectedMediaFile.getMetadata().getArtist() << "." << std::endl;
    std::cout << "[3]. Album: " << selectedMediaFile.getMetadata().getAlbum() << "." << std::endl;
    std::cout << "[4]. Genre: " << selectedMediaFile.getMetadata().getGenre() << "." << std::endl;
    std::cout << "     Length: " << selectedMediaFile.getMetadata().getLenght() << ". (Cannot be Changed)" << std::endl;
    std::cout << std::endl;
    mediaFileEditView::mainMenuOption();
}

void mediaFileEditView::mainMenuOption(){   
    std::cout << "Enter number 1~4 (edit metadata), p (play), q (quit), a (add to playlist)." << std::endl;
}

void mediaFileEditView::editMetadataView(appData& data){
    mediaFile selectedMediaFile = data.getSelectedMediaFile();
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    std::cout << "Edit Media File: " << std::endl;
    std::cout << "     File Name: " << selectedMediaFile.getfileName() << "." << std::endl;
    std::cout << std::endl;
    switch(data.getControlMode()){
        case EDIT_MEDIA_FILE_EDIT_TITLE:
            {   
                std::cout << "Current Title: " << selectedMediaFile.getMetadata().getTitle() << "." << std::endl;
                std::cout << "Enter New Title: " << std::endl;
            }
            break;
        case EDIT_MEDIA_FILE_EDIT_ALBUM:
            {   
                std::cout << "Current Album: " << selectedMediaFile.getMetadata().getAlbum() << "." << std::endl;
                std::cout << "Enter New Album: " << std::endl;
            }
            break;
        case EDIT_MEDIA_FILE_EDIT_ARTIST:
            {   
                std::cout << "Current Artist: " << selectedMediaFile.getMetadata().getArtist() << "." << std::endl;
                std::cout << "Enter New Artist: " << std::endl;
            }
            break;
        case EDIT_MEDIA_FILE_EDIT_GENRE:
            {   
                std::cout << "Current Genre: " << selectedMediaFile.getMetadata().getGenre() << "." << std::endl;
                std::cout << "Enter New Genre: " << std::endl;
            }
            break;
        default:
            break;
    }
}

void mediaFileEditView::addMediaFileToPlaylist(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    mediaFile selectedMediaFile = data.getSelectedMediaFile();
    std::cout << "Add to Playlist: " << std::endl;
    std::cout << "     File Name: " << selectedMediaFile.getfileName() << "." << std::endl;
    std::cout << "[1]. Title: " << selectedMediaFile.getMetadata().getTitle() << "." << std::endl;
    std::cout << "[2]. Artist: " << selectedMediaFile.getMetadata().getArtist() << "." << std::endl;
    std::cout << "[3]. Album: " << selectedMediaFile.getMetadata().getAlbum() << "." << std::endl;
    std::cout << "[4]. Genre: " << selectedMediaFile.getMetadata().getGenre() << "." << std::endl;
    std::cout << "     Length: " << selectedMediaFile.getMetadata().getLenght() << ". (Cannot be Changed)" << std::endl;
    std::cout << std::endl;
    std::cout << "Playlist: q (quit)" << std::endl;
    for(int i = 0; i < static_cast<int>(data.getPlaylistList().size()); i++){
        std::cout << i + 1 << ". " << data.getPlaylistList()[i].getPlaylistName() << "." << std::endl;
    }
}