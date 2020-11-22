#pragma once

#include <thread>
#include <atomic>
#include "MSNClient.h"
#include "ClientRepository.h"
#include "SocketServerException.h"
class MSNServer {
private:
	int _port;
	ISocket* _listenSocket;
	ClientRepository _clientRepo;
	void handleClient(IClientSocket* socket);
	void onClientConnected(IClientSocket* clientSocket);
public:
	MSNServer(int port, ClientRepository& repo);
	MSNServer(const MSNServer& obj);
	~MSNServer();
	void listen();
};