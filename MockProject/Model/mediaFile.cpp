#include "mediaFile.h"

mediaFile::mediaFile(std::string filePath) : filePath(filePath), metaData(filePath){
    mediaFile::getFileNameFromPath();
};

std::string mediaFile::getFilePath(){
    return filePath;
}

metadata mediaFile::getMetadata(){
    return metaData;
}

std::string mediaFile::getfileName(){
    return fileName;
}

void mediaFile::setMetadata(metadata newMetadata) {
    this->metaData.setNewMetadata(newMetadata);
}

void mediaFile::getFileNameFromPath(){
    size_t lastSlash = filePath.find_last_of('/');
    if (lastSlash != std::string::npos) {
        fileName = filePath.substr(lastSlash + 1);
    } else {
        fileName = filePath;
    }
}

void mediaFile::setFilename(std::string newName) {
    size_t lastSlash = filePath.find_last_of('/');
    std::string dir = (lastSlash != std::string::npos) ? filePath.substr(0, lastSlash + 1) : "";

    std::string newPath = dir + newName;

    // Tiến hành đổi tên file vật lý trên đĩa
    if (std::rename(filePath.c_str(), newPath.c_str()) == 0) {
        // Nếu đổi tên thành công thì cập nhật lại biến
        filePath = newPath;
        fileName = newName;
    } else {
        std::cerr << "Rename file failed: " << filePath << " -> " << newPath << std::endl;
    }
}