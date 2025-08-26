#include "sharedViewFunction.h"

void sharedViewFunction::displayPlaylistMediaFile(playlist pl){
    std::cout << "Playlist: " << pl.getPlaylistName() << std::endl;
    if (static_cast<int>(pl.getPlaylistMediaFile().size()) == 0){
        std::cout << "Playlist is empty" << std::endl;
        return;
    }
    for (int i = 0; i < static_cast<int>(pl.getPlaylistMediaFile().size()); i++){
        std::cout << i + 1 << "." << " Song: "  << pl.getPlaylistMediaFile()[i].getMetadata().getTitle() << " - by " << pl.getPlaylistMediaFile()[i].getMetadata().getArtist() << "." << std::endl;  
    }
    return;
}

void sharedViewFunction::displayCurrentPlaylist(appData& data){
    std::cout << "Current Playlist: " << data.getCurrentPlaylist().getPlaylistName() << std::endl;
}

void sharedViewFunction::displayMediaFile(mediaFile mediaFile){
    metadata md = mediaFile.getMetadata();
    std::cout << mediaFile.getfileName() << std::endl;
    std::cout << "🎵 Title " << md.getTitle() << " - " << md.getArtist() << "\n";
    std::cout << "📀 Album: " << md.getAlbum() << " | 🎼 Genre: " << md.getGenre() << "\n";
    std::cout << "⏱️ Length: " << md.getLenght() << " sec" << std::endl;
}

void sharedViewFunction::displayCurrentTrack(appData& data){
    mediaFile currentMediaFile = data.getCurrentMediaFile();
    std::cout << "Now Playing......." << std::endl;
    sharedViewFunction::displayMediaFile(currentMediaFile);
}

void sharedViewFunction::displayMediaLibrary(appData& data){
    std::cout << "Media File Library: " << std::endl;
    if (static_cast<int>(data.getMediaLibrary().size()) == 0){
        std::cout << "Media File Library is empty" << std::endl;
        return;
    }
    for (int i = 0; i < static_cast<int>(data.getMediaLibrary().size()); i++){
        std::cout << i + 1 << "." << " File: "  << data.getMediaLibrary()[i].getfileName() << std::endl;
    }
    return;
}