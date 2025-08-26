#include "sharedControllerFunction.h"

void sharedControllerFunction::loadSelectedPlaylist(appData& data){
    std::string playlistName = data.getSelectedPlaylist().getPlaylistName();
    for(int i = 0; i < static_cast<int>(data.getPlaylistList().size()); i++){
        if(data.getPlaylistList()[i].getPlaylistName() == playlistName){
            data.setSelectedPlaylist(data.getPlaylistList()[i]);
        }
    }
}

void sharedControllerFunction::loadCurrentPlaylist(appData& data){
    std::string playlistName = data.getCurrentPlaylist().getPlaylistName();
    for(int i = 0; i < static_cast<int>(data.getPlaylistList().size()); i++){
        if(data.getPlaylistList()[i].getPlaylistName() == playlistName){
            data.setCurrentPlaylist(data.getPlaylistList()[i]);
        }
    }
}

void sharedControllerFunction::loadPlaylist(appData& data, std::string& filename) {
    // Mở file JSON
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "❌ Không thể mở file " << filename << "\n";
        return;
    }

    json j;
    try {
        inFile >> j;  // Đọc dữ liệu JSON vào đối tượng j
    } catch (...) {
        std::cerr << "⚠️ JSON không hợp lệ.\n";
        return;
    }
    inFile.close();

    std::vector<playlist> list;

    // Kiểm tra xem "playlist" có tồn tại trong JSON không
    if (j.contains("playlist") && j["playlist"].is_object()) {
        // Lặp qua từng playlist trong JSON
        for (auto& [playlistName, songArray] : j["playlist"].items()) {
            playlist newPl(playlistName);  // Tạo một playlist mới
            if (songArray.is_array()) {
                // Lặp qua từng media file trong playlist
                for (const auto& path : songArray) {
                    if (path.is_string()) {
                        mediaFile newMf(path);  // Tạo media file từ path
                        newPl.addMediaFile(newMf);  // Thêm media file vào playlist
                    }
                }
            }
            list.push_back(newPl);  // Thêm playlist vào danh sách
        }
        std::cout << "✅ Đã tải playlist từ file.\n";
        data.setPlaylistList(list);  // Cập nhật danh sách playlist trong appData
    } else {
        std::cout << "📂 Không tìm thấy playlist trong file.\n";
    }

    // Debug: Kiểm tra dữ liệu đã được tải vào appData chưa
    std::cout << "Danh sách playlist sau khi load:\n";
}

void sharedControllerFunction::loadMediaFileLib(appData& data, std::string& filename) {
    std::vector<mediaFile> newLib;

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Không thể mở file JSON: " << filename << std::endl;
        return;
    }

    try {
        json j;
        inFile >> j;

        if (j.contains("mediaLibrary") && j["mediaLibrary"].is_array()) {
            for (const auto& path : j["mediaLibrary"]) {
                if (path.is_string()) {
                    mediaFile newMf(path.get<std::string>());
                    newLib.push_back(newMf);
                }
            }
        } else {
            std::cerr << "File JSON không chứa mảng mediaLibrary hợp lệ.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Lỗi khi đọc JSON: " << e.what() << std::endl;
    }

    // Gán vào thư viện
    data.setMediaLibrary(newLib);
}

void sharedControllerFunction::loadMediaFileToPlaylist(std::string& filename) {
    // Đọc log JSON
    json logJson;
    std::ifstream logIn(filename);
    if (!logIn.is_open()) {
        std::cerr << "❌ Không thể mở file log: " << filename << std::endl;
        return;
    }

    try {
        logIn >> logJson;
    } catch (const std::exception& e) {
        std::cerr << "❌ JSON lỗi: " << e.what() << std::endl;
        return;
    }
    logIn.close();

    // Kiểm tra mediaLibrary trong logJson
    if (!logJson.contains("mediaLibrary") || !logJson["mediaLibrary"].is_array()) {
        std::cerr << "⚠️ Không có mediaLibrary hợp lệ trong file log\n";
        return;
    }

    // Ghi playlist "mediaFile" vào log JSON
    json mediaArray = json::array();
    for (const auto& path : logJson["mediaLibrary"]) {
        if (path.is_string()) {
            mediaArray.push_back(path);
        }
    }

    logJson["playlist"]["mediaFile"] = mediaArray;

    // Ghi lại file log
    std::ofstream logOut(filename);
    if (!logOut.is_open()) {
        std::cerr << "⚠️ Không thể mở file log để ghi: " << filename << std::endl;
        return;
    }

    logOut << logJson.dump(4);
    logOut.close();

    std::cout << "✅ Đã cập nhật playlist 'mediaFile' trong file log JSON: " << filename << std::endl;
}

void sharedControllerFunction::loadSelectedMediaFile(appData& data){
    std::string selectedMediaFilePath = data.getSelectedMediaFile().getFilePath();
    mediaFile mf = mediaFile(selectedMediaFilePath);
    data.setSelectedMediaFile(mf);
}

void sharedControllerFunction::loadCurrentMediaFile(appData& data){
    std::string currentMediaFilePath = data.getCurrentMediaFile().getFilePath();
    mediaFile mf = mediaFile(currentMediaFilePath);
    data.setCurrentMediaFile(mf);
}