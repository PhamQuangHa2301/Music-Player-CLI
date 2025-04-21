#ifndef METADATA_H
#define METADATA_H

#include <iostream>
#include <string>
#include <taglib/fileref.h>
#include <taglib/tag.h>

class metadata {
    private:
        std::string filePath;
        std::string title;
        std::string artist;
        std::string album;
        std::string genre;
        int mediaLengthInSecond;
    public:
        //Constructor
        metadata(){};
        metadata(std::string filePath);
        ~metadata(){};
        std::string getFilePath();
        std::string getTitle();
        std::string getArtist();
        std::string getAlbum();
        std::string getGenre();
        int getLenght();

        // Các hàm setter
        void setNewMetadata(metadata newData);

        void setTitle(std::string t);
        void setArtist(std::string a);
        void setAlbum(std::string al);
        void setGenre(std::string g);
        void setMediaLengthInSecond(int len);
};

#endif