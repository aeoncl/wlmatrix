#pragma once
#include "TCPServer.h"
#include "MSNClient.h"
class MSNNotificationServer : public TCPServer {
	protected:
		void handleClient(IClientSocket* socket) override {
			std::cout << "Started MSNClient thread." << std::endl;
			auto clientInfo = std::make_shared<ClientInfo>();
			_clientRepo->addClient(clientInfo);
			auto client = MSNClient(socket, clientInfo);
			client.listen();
		};
	public :
		MSNNotificationServer(ClientInfoRepository* repo) : TCPServer("127.0.0.1", 1863, repo) {};
};

