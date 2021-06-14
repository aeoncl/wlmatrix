#include "WinSockClientSocket.h"
#include "StringUtils.h"
#include <iostream>
#include <thread>
#include <chrono>
#pragma comment(lib, "Ws2_32.lib")

WinSockClientSocket::~WinSockClientSocket() {
    this->_listening.exchange(false);
	closesocket(this->_socket);
    std::cout << "Destroyed WinsockClientSocket" << std::endl;
}

void WinSockClientSocket::send(std::string message) {
    int iSendResult = ::send(this->_socket, message.c_str(), message.length(), 0);
    if (iSendResult == SOCKET_ERROR) {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
    }
    else {
        std::cout << "<< " << message << std::endl;
    }
    return;
}

WinSockClientSocket::WinSockClientSocket(const WinSockClientSocket& obj) {
    this->_socket = obj._socket;
    this->_ip = obj._ip;
}

void WinSockClientSocket::receive(std::function<void(std::string)> callback) {
    this->_listening.store(true);
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    std::string message = "";
    bool keepListening = true;
    do {
        iResult = recv(this->_socket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            std::string currentPart = StringUtils::getStringForShittyBuffer(recvbuf, recvbuflen, iResult);
            message.append(currentPart);
            if (iResult < recvbuflen) {
                //complete message not hitting buffer length
                callback(message);
                message.clear();
            }
        }
        else if (iResult == 0) {
            std::cout << "Client Disconnected...\n";
            this->_listening.exchange(false);
            return;
        }
        else {
            std::cerr << "recv failed :" << WSAGetLastError() << std::endl;
            return;
        }
    } while (iResult > 0 || (!_listening.compare_exchange_weak(keepListening, false) && keepListening));
}

std::string WinSockClientSocket::getIpAddress() {
    return this->_ip;

}

bool WinSockClientSocket::isListening()
{
    return _listening.load();
}