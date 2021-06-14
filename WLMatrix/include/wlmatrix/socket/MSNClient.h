#pragma once
#include <atomic>
#include <string>
#include "ISocket.h"
#include "MSNSwitchboard.h"
#include "ClientInfo.h"
class MSNClient {
	private:
		IClientSocket* _clientSocket;
		std::atomic<bool> _listening;
		std::shared_ptr<ClientInfo> _clientInfo;
		std::function<void(MSNClient*)> _destructionCallback;
	public:
		MSNClient(IClientSocket* clientSocket, std::shared_ptr<ClientInfo> info);
		MSNClient(const MSNClient& obj);
		~MSNClient();
		bool isListening() { return _listening.load(); };
		void listen();
		void onMessageReceived(std::string message);
		std::shared_ptr<ClientInfo> getClientInfo();
		void registerDestructionCallback(std::function<void(MSNClient*)> callback);
};