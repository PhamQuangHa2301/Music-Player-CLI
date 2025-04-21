#ifndef UARTCONTROL_H
#define UARTCONTROL_h

#include "../Controller/generalController.h"
#include "../View/generalViewController.h"

#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <chrono>
#include <fcntl.h>
#include <termios.h>
#include <string>

void uartControl(std::string message, appData& data, std::chrono::milliseconds diff);
int setupUART(const std::string& device);
bool checkUARTConnection(const std::string& device);
void setBoardStatus(bool status, appData& data);
void readFromUART(const std::string& device, appData& data, std::atomic<bool>& running);

#endif