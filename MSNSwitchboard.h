#pragma once
#include "IClientSocket.h"
#include <thread>
#include <atomic>

class IMSNPInterpreter;

/* a MSN switchboard is instanciated each time a MSNClient creates a conversation. */
class MSNSwitchboard {
	private :
		IClientSocket* _clientSocket;
		std::atomic<bool> _listening;
	public : 
		MSNSwitchboard(IClientSocket* clientSocket) : _clientSocket(clientSocket) {};
		MSNSwitchboard(const MSNSwitchboard& obj);
		~MSNSwitchboard();
		void listen();
};

