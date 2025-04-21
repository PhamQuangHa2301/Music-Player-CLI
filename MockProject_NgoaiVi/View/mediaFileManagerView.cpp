#include "mediaFileManagerView.h"

void mediaFileManagerView::mainView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayMediaLibrary(data);
    mediaFileManagerView::displayMainViewOption();
}

void mediaFileManagerView::displayMainViewOption(){
    std::cout << "Enter:a (add single media file), b (browse directory), s (select media file), q (quit)" << std::endl;
}

void mediaFileManagerView::addNewFilePathView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayMediaLibrary(data);
    std::cout << std::endl;
    std::cout << "Enter Media File Path (q to quit): " << std::endl;
}

void mediaFileManagerView::browseDirectoryView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayMediaLibrary(data);
    std::cout << std::endl;
    std::cout << "Enter Directory Path (q to quit): " << std::endl;
}

void mediaFileManagerView::selectMediaFileView(appData& data){
    system("clear");
    sharedViewFunction::displayBoardStatusAndVolumn(data);
    sharedViewFunction::displayMediaLibrary(data);
    std::cout << std::endl;
    std::cout << "Enter Number In Range (1 ~ " << static_cast<int>(data.getMediaLibrary().size()) << ") to Select, q (quit): " << std::endl;
}