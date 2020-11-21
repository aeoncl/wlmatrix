#include "MSNClient.h"
#include "StringUtils.h"
#include <iterator>
#include <iostream>

/* Constructor */
MSNClient::MSNClient(IClientSocket* clientSocket)
{
    this->_clientSocket = clientSocket;
}

/* Copystructor */
MSNClient::MSNClient(const MSNClient& obj) {
	_clientSocket = obj._clientSocket;
}

/* Destructor */
MSNClient::~MSNClient() {
    std::cout << "Client destroyed\n";
    //Client destroyed
}

void MSNClient::listen() {
    this->_clientSocket->receive(std::bind(&MSNClient::onMessageReceived, this, std::placeholders::_1));
}

/* Private Methods */

/* Callback */
void MSNClient::onMessageReceived(std::string message) {
    //Called when a message is received
    std::cout << "Message received : " << message << "\n";
    //todo respond
}




