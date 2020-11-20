#include "MSNClient.h"
#include "StringUtils.h"
#include <iterator>
#include <iostream>

/* Constructor */
MSNClient::MSNClient(SOCKET& clientSocket)
{
    this->_clientSocket = clientSocket;
}

/* Copystructor */
MSNClient::MSNClient(const MSNClient& obj) {
	_clientSocket = obj._clientSocket;
}

/* Destructor */
MSNClient::~MSNClient() {
	closesocket(_clientSocket);
    std::cout << "Client destroyed\n";
    //Client destroyed
}

/* Private Methods */
void MSNClient::listen() {
    this->_listening.store(true);
    char recvbuf[DEFAULT_BUFLEN];
    int iResult, iSendResult;
    int recvbuflen = DEFAULT_BUFLEN;
    do {
            iResult = recv(this->_clientSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0) {
                auto message = StringUtils::getStringForShittyBuffer(recvbuf, iResult);

                // Echo the buffer back to the sender
                //iSendResult = send(clientSocket, recvbuf, iResult, 0);
                //if (iSendResult == SOCKET_ERROR) {
                //    printf("send failed: %d\n", WSAGetLastError());
                //    return;
                //}
                //printf("Bytes sent: %d\n", iSendResult);
                std::cout << ">>>" << message;
            } else if (iResult == 0) {
                std::cout << "Client Disconnected...\n";
                this->_listening.store(false);
            } else {
                std::cerr << "recv failed :" << WSAGetLastError() << "\n";
                return;
            }
    } while (iResult > 0 && isListening());
}

void MSNClient::send(SOCKET& clientSocket, std::string msg) {

}


