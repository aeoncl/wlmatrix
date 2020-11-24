#pragma once
#include "TCPServer.h"
#include "MSNClient.h"
class MSNNotificationServer : public TCPServer {
	protected:
		void handleClient(IClientSocket* socket) override {
			std::cout << "Started MSNClient thread." << std::endl;
			auto client = std::make_shared<MSNClient>(socket);
			//this->_clientRepo.addClient(client);
			client->listen();
		};
	public :
		MSNNotificationServer(ClientInfoRepository& repo) : TCPServer("127.0.0.1", 1863, repo) {};
};

