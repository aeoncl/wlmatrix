#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <atomic>
#include <deque>
#include "MSNClient.h"
#include "SocketServerException.h"

class SocketServer {
private:
	int _port;
	std::atomic_bool _listening;
	SOCKET _listenSocket;
	WSADATA* initWinsock();
	int listen(SOCKET listenSocket);
	std::deque<MSNClient> _clients;
	void createServer();
	addrinfo* getAddressInfo();
	void createSocket(addrinfo* addrInfo);
	void bindSocket(addrinfo* addrInfo);
	void handleClient(SOCKET socket);
public:
	SocketServer(int port);
	SocketServer(const SocketServer& obj);
	~SocketServer();
	bool isListening();
	void listen();
	void listenAsync();
	void stop();
};