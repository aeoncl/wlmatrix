#include "MSNSwitchboard.h"

MSNSwitchboard::MSNSwitchboard(const MSNSwitchboard& obj) {
	this->_clientSocket = obj._clientSocket;
	this->_identifier = obj._identifier;
	this->_interpreter = obj._interpreter;
}

MSNSwitchboard::~MSNSwitchboard() {
}
