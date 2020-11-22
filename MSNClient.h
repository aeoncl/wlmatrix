#pragma once
#include <atomic>
#include <string>
#include "ISocket.h"
#include "MSNSwitchboard.h"
#include "IMSNPCommand.h"

class MSNClient {
	private:
		IClientSocket* _clientSocket;
		std::vector<std::shared_ptr<MSNSwitchboard>> _conversations;
		std::atomic<bool> _listening;
		std::string _identifier;
		int _dialectVersion;
	public:
		MSNClient(IClientSocket* clientSocket);
		MSNClient(const MSNClient& obj);
		~MSNClient();
		bool isListening() { return _listening.load(); };
		void listen();
		void onMessageReceived(std::string message);
		void addSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard);
		void removeSwitchboard(std::shared_ptr<MSNSwitchboard> switchboard);
		void setDialectVersion(int version);
		std::string getId();
};