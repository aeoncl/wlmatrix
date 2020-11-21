#pragma once

#include <thread>
#include <atomic>
#include <deque>
#include "MSNClient.h"
#include "SocketServerException.h"
class MSNServer {
private:
	int _port;
	ISocket* _listenSocket;
	std::vector<std::shared_ptr<MSNClient>> _clients;
	void handleClient(IClientSocket* socket);
	void onClientConnected(IClientSocket* clientSocket);
	void eraseClient(std::shared_ptr<MSNClient> client);
public:
	MSNServer(int port);
	MSNServer(const MSNServer& obj);
	~MSNServer();
	void listen();
};