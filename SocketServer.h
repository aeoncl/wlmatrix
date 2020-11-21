#pragma once

#include <thread>
#include <atomic>
#include <deque>
#include "MSNClient.h"
#include "SocketServerException.h"
class SocketServer {
private:
	int _port;
	ISocket* _listenSocket;
	std::vector<std::shared_ptr<MSNClient>> _clients;
	void handleClient(IClientSocket* socket);
	void onClientConnected(IClientSocket* clientSocket);
	void eraseClient(std::shared_ptr<MSNClient> client);
public:
	SocketServer(int port);
	SocketServer(const SocketServer& obj);
	~SocketServer();
	void listen();
};