#pragma once
#include "TCPServer.h"
#include "MSNSwitchboard.h"
class MSNSwitchboardServer : public TCPServer {
	protected:
		void handleClient(IClientSocket* socket) override {
			std::cout << "Started MSNSwitchboard thread." << std::endl;
			auto client = std::make_shared<MSNSwitchboard>(socket);
			//this->_clientRepo.addClient(client);
			client->listen();
		};
	public :
		MSNSwitchboardServer(ClientInfoRepository* repo) : TCPServer("127.0.0.1", 1864, repo) {};
};

