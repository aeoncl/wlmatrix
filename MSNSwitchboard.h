#pragma once
#include "IClientSocket.h"
#include <thread>
#include <atomic>

class IMSNPInterpreter;

/* a MSN switchboard is instanciated each time a MSNClient creates a conversation. */
class MSNSwitchboard {
	private :
		IClientSocket* _clientSocket;
		IMSNPInterpreter* _interpreter;
		std::atomic<bool> _listening;
		std::thread _thread;
		std::string _identifier;
	public : 
		MSNSwitchboard(IClientSocket* clientSocket, IMSNPInterpreter* interpreter) : _clientSocket(clientSocket), _interpreter(interpreter) {};
		MSNSwitchboard(const MSNSwitchboard& obj);
		~MSNSwitchboard();
};

