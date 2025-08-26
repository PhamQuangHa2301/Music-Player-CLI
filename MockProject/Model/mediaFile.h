#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <iostream>
#include <string>
#include "metaData.h"

enum mediaType {
    music,
    video
};

class mediaFile {
    protected:
        std::string filePath;
        std::string fileName;
        metadata metaData;
    public:
        //Constructor
        mediaFile(){};
        mediaFile(std::string filePath);
        ~mediaFile(){};
        //Getter
        std::string getFilePath();
        metadata getMetadata();
        std::string getfileName();
        //Setter
        void setMetadata(metadata newMetadata);
        void getFileNameFromPath();
        void setFilename(std::string newName);
};

#endif