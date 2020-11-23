#pragma once
#include <atomic>
#include <string>
#include "ISocket.h"
#include "MSNSwitchboard.h"

class MSNClient {
	private:
		IClientSocket* _clientSocket;
		std::atomic<bool> _listening;
	public:
		MSNClient(IClientSocket* clientSocket);
		MSNClient(const MSNClient& obj);
		~MSNClient();
		bool isListening() { return _listening.load(); };
		void listen();
		void onMessageReceived(std::string message);
};