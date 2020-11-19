#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <atomic>
#include "SocketServerException.h"

class SocketServer {
private:
	int _port;
	std::atomic_bool _listening;
	SOCKET _listenSocket;
	WSADATA* initWinsock();
	int listen(SOCKET listenSocket);
	void createServer();
	addrinfo* getAddressInfo();
	void createSocket(addrinfo* addrInfo);
	void bindSocket(addrinfo* addrInfo);

public:
	SocketServer(int port);
	SocketServer(const SocketServer& obj);
	~SocketServer();
	bool isListening();
	void listen();
	void listenAsync();
	void stop();
};