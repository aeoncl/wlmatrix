#include "MSNClient.h"
#include "StringUtils.h"
#include <iostream>
#include "MSNPInterpreterFactory.h"


/* Constructor */
MSNClient::MSNClient(IClientSocket* clientSocket) {
    this->_clientSocket = clientSocket;
    this->_interpreter = MSNPInterpreterFactory::getInterpreter(-1);
    std::cout << "MSNClient constructed" << std::endl;
}

/* Copystructor */
MSNClient::MSNClient(const MSNClient& obj) {
	_clientSocket = obj._clientSocket;
    _interpreter = obj._interpreter;
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
    std::cout << "Message received : " << message << std::endl;
    auto lines = StringUtils::splitLines(message);
    for (auto line : lines) {
        auto response = _interpreter->interpretMessage(line, *this);
        this->_clientSocket->send(response);
    }
    //todo interpret command & respond.
}

void MSNClient::addSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard) {
    this->_conversations.push_back(switchboard);
}

void MSNClient::removeSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard) {
    //TODO
}

void MSNClient::setInterpreter(const IMSNPInterpreter* interpreter) {
    this->_interpreter = interpreter;
}

std::string MSNClient::getId() {
    return this->_identifier;
}




