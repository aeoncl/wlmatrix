#include "MSNClient.h"
#include "StringUtils.h"
#include <iostream>
#include "MSNPCommandHandlerFactory.h"


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
    std::cout << ">>>>>" << message << std::endl;

    auto lines = StringUtils::splitLines(message);
    for (auto line : lines) {
        std::cout << ">> " << line << std::endl;
        auto matchResults = std::smatch{};
        bool const hasMatches = std::regex_search(line, matchResults, std::regex("([A-Z]{3})"));
        if (hasMatches) {
            auto commandName = matchResults[0].str();
            auto commandHandler = MSNPCommandHandlerFactory::getCommand(commandName);
            auto responses = commandHandler->executeCommand(line, *this, -1);//TODO
            for (auto response : responses) {
                this->_clientSocket->send(response);
            }
        }
    }
}



