#pragma once
#include <atomic>
#include <thread>
#include <string>
#include <WinSock2.h>
#include "ISocket.h"
#include "IMSNPInterpreter.h"

class MSNClient {
	private:
		IClientSocket* _clientSocket;
		IMSNPInterpreter* _interpreter;
		std::atomic<bool> _listening;
		std::thread _thread;
	public:
		MSNClient(IClientSocket* clientSocket);
		MSNClient(const MSNClient& obj);
		~MSNClient();
		bool isListening() { return _listening.load(); };
		void listen();
		void onMessageReceived(std::string message);
};