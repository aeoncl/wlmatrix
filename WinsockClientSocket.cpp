#include "WinsockClientSocket.h"
#include "StringUtils.h"
#include <iostream>

WinsockClientSocket::~WinsockClientSocket() {
	closesocket(this->_socket);
    std::cout << "Destroyed WinsockClientSocket.\n";
}

void WinsockClientSocket::send(std::string) {

}

WinsockClientSocket::WinsockClientSocket(const WinsockClientSocket& obj) {
    this->_socket = obj._socket;
}

void WinsockClientSocket::receive(std::function<void(std::string)> callback) {
    this->_listening.store(true);
    char recvbuf[DEFAULT_BUFLEN];
    int iResult, iSendResult;
    int recvbuflen = DEFAULT_BUFLEN;
    do {
        iResult = recv(this->_socket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            auto message = StringUtils::getStringForShittyBuffer(recvbuf, iResult);

            // Echo the buffer back to the sender
            //iSendResult = send(clientSocket, recvbuf, iResult, 0);
            //if (iSendResult == SOCKET_ERROR) {
            //    printf("send failed: %d\n", WSAGetLastError());
            //    return;
            //}
            //printf("Bytes sent: %d\n", iSendResult);
            callback(message);
        }
        else if (iResult == 0) {
            std::cout << "Client Disconnected...\n";
            this->_listening.store(false);
        }
        else {
            std::cerr << "recv failed :" << WSAGetLastError() << "\n";
            return;
        }
    } while (iResult > 0 && isListening());
}

bool WinsockClientSocket::isListening()
{
    return this->_listening.load();
}
