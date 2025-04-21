#include <iostream>
#include <fstream>
#include <dirent.h>
#include <nlohmann/json.hpp>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <chrono>
#include <fcntl.h>
#include <termios.h>
#include <string>

#include "Model/applicationData.h"
#include "Controller/generalController.h"
#include "View/generalViewController.h"
#include "Uart/uartControl.h"

std::atomic<bool> running(true);  // cờ để dừng cả 2 luồng khi cần

void controlerLoop(const std::string& filename, appData& data) {
    std::string command;
    generalController::controllerDo(filename, command, data);
    generalViewController::viewDo(data);
    
    while (data.getControlMode() != QUIT_PROGRAM && running.load()) {
        std::getline(std::cin, command);
        generalController::controllerDo(filename, command, data);
        generalViewController::viewDo(data);
    }
    running.store(false);  // nếu thoát khỏi vòng lặp, dừng luôn luồng UART
}

void uartListener(appData& data) {
    std::string uartPort = "/dev/ttyACM1"; 
    readFromUART(uartPort, data, running);
}

int main() {
    std::string filename = "log.json";
    appData data;

    std::thread controlThread(controlerLoop, std::ref(filename), std::ref(data));
    std::thread uartThread(uartListener, std::ref(data));

    controlThread.join();
    uartThread.join();

    return 0;
}