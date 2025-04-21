#include "metaData.h"

metadata::metadata(std::string filePath) {
    this->filePath = filePath;
    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();
        this->title = tag->title().to8Bit();
        this->artist = tag->artist().to8Bit();
        this->album = tag->album().to8Bit();
        this->genre = tag->genre().to8Bit();
        if (file.audioProperties()) {
            this->mediaLengthInSecond = file.audioProperties()->lengthInSeconds();
        } else {
            this->mediaLengthInSecond = 0;
        }
    }
}

std::string metadata::getFilePath(){
    return filePath;
}

std::string metadata::getTitle(){
    return title;
}

std::string metadata::getArtist(){
    return artist;
}

std::string metadata::getAlbum(){
    return album;
}

std::string metadata::getGenre(){
    return genre;
}

int metadata::getLenght(){
    return mediaLengthInSecond;
}

void metadata::setNewMetadata(metadata newData){
    if(newData.getFilePath() != this->filePath){
        return;
    }
    else{
        if(newData.getTitle() != this->title){
            metadata::setTitle(newData.getTitle());
        }
        if(newData.getArtist() != this->artist){
            metadata::setArtist(newData.getArtist());
        }
        if(newData.getAlbum() != this->album){
            metadata::setAlbum(newData.getAlbum());
        }
        if(newData.getGenre() != this->genre){
            metadata::setGenre(newData.getGenre());
        }
    }
}

void metadata::setTitle(std::string t){
    title = t; 
    TagLib::FileRef file(this->filePath.c_str());
    if(!file.isNull() && file.tag()){
        TagLib::Tag *tag = file.tag();
        tag->setTitle(t);
        file.file()->save();
    }
}

void metadata::setArtist(std::string a){ 
    artist = a; 
    TagLib::FileRef file(this->filePath.c_str());
    if(!file.isNull() && file.tag()){
        TagLib::Tag *tag = file.tag();
        tag->setArtist(a);
        file.file()->save();
    }
}

void metadata::setAlbum(std::string al){ 
    album = al; 
    TagLib::FileRef file(this->filePath.c_str());
    if(!file.isNull() && file.tag()){
        TagLib::Tag *tag = file.tag();
        tag->setAlbum(al);
        file.file()->save();
    }
}

void metadata::setGenre(std::string g){ 
    genre = g; 
    TagLib::FileRef file(this->filePath.c_str());
    if(!file.isNull() && file.tag()){
        TagLib::Tag *tag = file.tag();
        tag->setGenre(g);
        file.file()->save();
    }
}

void metadata::setMediaLengthInSecond(int len){ 
    mediaLengthInSecond = len; 
}