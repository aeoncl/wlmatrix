#include "MSNSwitchboard.h"

MSNSwitchboard::MSNSwitchboard(const MSNSwitchboard& obj) {
	this->_clientSocket = obj._clientSocket;
}

MSNSwitchboard::~MSNSwitchboard() {
}

void MSNSwitchboard::listen() {
}
