#include "uartControl.h"

void uartControl(std::string message, appData& data, std::chrono::milliseconds diff){
    if (message == "P") {
        musicPlayController::pauseOrResume(data);
    }
    else if (message == "N") {
        if(diff.count() < 1000){
            musicPlayController::previousTrack(data);
            musicPlayController::previousTrack(data);
            generalViewController::viewDo(data);
        }
        else {
            musicPlayController::nextTrack(data);
            generalViewController::viewDo(data);
        }
    }
    else {
        musicPlayController::uartSetVolumn(message, data);
        generalViewController::viewDo(data);
    }
}

int setupUART(const std::string& device) {
    int serialPort = open(device.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (serialPort < 0) {
        std::cerr << "Không thể mở UART: " << device << std::endl;
        return -1;
    }

    struct termios tty;
    if (tcgetattr(serialPort, &tty) != 0) {
        std::cerr << "Lỗi lấy cấu hình UART\n";
        close(serialPort);
        return -1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_iflag &= ~IGNBRK;                         // disable break processing
    tty.c_lflag = 0;                                // no signaling chars, no echo
    tty.c_oflag = 0;                                // no remapping, no delays
    tty.c_cc[VMIN]  = 1;                            // read blocks until at least 1 char
    tty.c_cc[VTIME] = 1;                            // timeout (tenths of seconds)

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // shut off xon/xoff ctrl
    tty.c_cflag |= (CLOCAL | CREAD);                // ignore modem controls, enable reading
    tty.c_cflag &= ~(PARENB | PARODD);              // no parity
    tty.c_cflag &= ~CSTOPB;                         // 1 stop bit
    tty.c_cflag &= ~CRTSCTS;                        // no hardware flow control

    if (tcsetattr(serialPort, TCSANOW, &tty) != 0) {
        std::cerr << "Lỗi cấu hình UART\n";
        close(serialPort);
        return -1;
    }

    return serialPort;
}

bool checkUARTConnection(const std::string& device) {
    int fd = open(device.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        return false;
    }
    close(fd);
    return true;
}

void setBoardStatus(bool status, appData& data){
    if(status != data.getBoardConnectStatus()){
        data.setIsBoardConnectStatus(status);
        generalViewController::viewDo(data);
    }
} 

void readFromUART(const std::string& device, appData& data, std::atomic<bool>& running) {
    int serialPort = -1;

    // Loop kết nối lại nếu chưa kết nối
    while (running.load() && serialPort < 0) {
        if (checkUARTConnection(device)) {
            serialPort = setupUART(device);
            if (serialPort >= 0) {
                setBoardStatus(true, data);
            }
        } else {
            setBoardStatus(false, data);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    setBoardStatus(true, data);
    std::string buffer;
    auto lastTime = std::chrono::steady_clock::now();
    char ch;

    while (running.load()) {
        int n = read(serialPort, &ch, 1);
        if (n > 0) {
            if (ch == '\n') {
                std::string message = buffer;
                buffer.clear();

                auto now = std::chrono::steady_clock::now();
                auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime);
                lastTime = now;
                uartControl(message, data, diff);
            } else {
                buffer += ch;
            }
        } else if (n == 0 || n < 0) {
            // Có thể đã bị ngắt kết nối
            close(serialPort);
            setBoardStatus(false, data);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            readFromUART(device, data, running);  // gọi lại chính nó để kết nối lại
            return;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    close(serialPort);
    setBoardStatus(false, data);
}