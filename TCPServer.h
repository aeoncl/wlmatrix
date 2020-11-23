#pragma once
#include <thread>
#include <atomic>
#include "MSNClient.h"
#include "ClientInfoRepository.h"
#include "SocketServerException.h"

class TCPServer {
protected:
	virtual void handleClient(IClientSocket* socket);
private:
	int _port;
	ISocket* _listenSocket;
	ClientInfoRepository _clientRepo;
	void onClientConnected(IClientSocket* clientSocket);
public:
	TCPServer(std::string url, int port, ClientInfoRepository& repo);
	TCPServer(const TCPServer& obj);
	~TCPServer();
	void listen();
};