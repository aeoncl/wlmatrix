#include "MSNClient.h"
#include "StringUtils.h"
#include <iostream>
#include "MSNPCommandHandlerFactory.h"
#include "MSNPCommandParser.h"

/* Constructor */
MSNClient::MSNClient(IClientSocket* clientSocket) {
    this->_clientSocket = clientSocket;
    std::cout << "MSNClient constructed" << std::endl;
}

/* Copystructor */
MSNClient::MSNClient(const MSNClient& obj) {
	_clientSocket = obj._clientSocket;
}

/* Vaati */
MSNClient::~MSNClient() {
    std::cout << "Client destroyed" << std::endl;
}

void MSNClient::listen() {
    this->_clientSocket->receive(std::bind(&MSNClient::onMessageReceived, this, std::placeholders::_1));
}

/* Private Methods */

/* Callback */
void MSNClient::onMessageReceived(std::string message) {
    //Called when a message is received
    auto lines = MSNPCommandParser::splitMessage(message);
    for (auto line : lines) {
        std::cout << ">> " << line << std::endl;
        auto commandName = line.substr(0,3);
        auto commandHandler = MSNPCommandHandlerFactory::getCommand(commandName);
        auto responses = commandHandler->executeCommand(line, *this, -1);
        for (auto response : responses) {
                this->_clientSocket->send(response);
        }
    }
}



