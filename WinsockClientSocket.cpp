#include "WinSockClientSocket.h"
#include "StringUtils.h"
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

WinSockClientSocket::~WinSockClientSocket() {
	closesocket(this->_socket);
    std::cout << "Destroyed WinsockClientSocket" << std::endl;
}

void WinSockClientSocket::send(std::string message) {
    int iSendResult = ::send(this->_socket, message.c_str(), message.length(), 0);
    if (iSendResult == SOCKET_ERROR) {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
    }
    else {
        std::cout << ">> " << message << std::endl;
    }
    return;
}

WinSockClientSocket::WinSockClientSocket(const WinSockClientSocket& obj) {
    this->_socket = obj._socket;
}

void WinSockClientSocket::receive(std::function<void(std::string)> callback) {
    this->_listening.store(true);
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    do {
        iResult = recv(this->_socket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            auto message = StringUtils::getStringForShittyBuffer(recvbuf, iResult);
            //Message received
            callback(message);
        }
        else if (iResult == 0) {
            std::cout << "Client Disconnected...\n";
            this->_listening.store(false);
        }
        else {
            std::cerr << "recv failed :" << WSAGetLastError() << std::endl;
            return;
        }
    } while (iResult > 0 && isListening());
}

bool WinSockClientSocket::isListening()
{
    return this->_listening.load();
}
