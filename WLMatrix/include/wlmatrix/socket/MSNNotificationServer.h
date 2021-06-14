#pragma once
#include "TCPServer.h"
#include "MSNClient.h"
class MSNNotificationServer : public TCPServer {
	protected:
		void onClientDisconected(MSNClient* client) {
			_clientRepo->removeClient(client->getClientInfo());
			delete client;
		};

		void handleClient(IClientSocket* socket) override {
			std::cout << "Started MSNClient thread." << std::endl;
			auto clientInfo = std::make_shared<ClientInfo>();
			_clientRepo->addClient(clientInfo);
			auto client = new MSNClient(socket, clientInfo);
			client->registerDestructionCallback(std::bind(&MSNNotificationServer::onClientDisconected, this, std::placeholders::_1));
			client->listen();
		};
	public :
		MSNNotificationServer(ClientInfoRepository* repo) : TCPServer("127.0.0.1", 1863, repo) {};
};

