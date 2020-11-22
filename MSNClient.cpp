#include "MSNClient.h"
#include "StringUtils.h"
#include <iostream>
#include "MSNPCommandFactory.h"


/* Constructor */
MSNClient::MSNClient(IClientSocket* clientSocket) {
    this->_clientSocket = clientSocket;
    this->_dialectVersion = -1;
    std::cout << "MSNClient constructed" << std::endl;
}

/* Copystructor */
MSNClient::MSNClient(const MSNClient& obj) {
	_clientSocket = obj._clientSocket;
    _dialectVersion = obj._dialectVersion;
}

/* Destructor */
MSNClient::~MSNClient() {
    std::cout << "Client destroyed" << std::endl;
    //Client destroyed
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
            auto commandHandler = MSNPCommandFactory::getCommand(commandName);
            auto responses = commandHandler->executeCommand(line, *this, _dialectVersion);
            for (auto response : responses) {
                this->_clientSocket->send(response);
            }
        }
    }
}



void MSNClient::addSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard) {
    this->_conversations.push_back(switchboard);
}

void MSNClient::removeSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard) {
    //TODO
}

void MSNClient::setDialectVersion(int version){
    this->_dialectVersion = version;
}

std::string MSNClient::getId() {
    return this->_identifier;
}




