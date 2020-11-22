#include "WinSockSocket.h"
#include "WinsockClientSocket.h"
#include <iostream>
#include "SocketServerException.h"
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

/* Constructor */
WinSockSocket::WinSockSocket(int port) {
	this->_port = port;
	this->_listenSocket = INVALID_SOCKET;
	this->createSocket();
}

/* Copystructor */
WinSockSocket::WinSockSocket(const WinSockSocket& obj) {
	this->_port = obj._port;
	this->_listenSocket = obj._listenSocket;
}

/* Destructor */
WinSockSocket::~WinSockSocket() {
	std::cout << "Destroying winsock socket on port " << _port << std::endl;
	closesocket(_listenSocket);
	WSACleanup();
}

/* Private methods */
void WinSockSocket::createSocket() {
	try {
		this->initWinsock();
		auto addrInfo = this->getAddressInfo();
		this->createSocket(addrInfo);
		this->bindSocket(addrInfo);
		freeaddrinfo(addrInfo);
	}
	catch (SocketServerException& e) {
		throw;
	}
}

WSADATA* WinSockSocket::initWinsock() {
	WORD wsVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	int wsStatus = WSAStartup(wsVersion, &wsaData);
	if (wsStatus != 0) {
		throw SocketServerException("InitWinSocket - Cannot initialize winsock");
	}
	return &wsaData;
}

addrinfo* WinSockSocket::getAddressInfo() {
	struct addrinfo* result;
	struct addrinfo hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	std::string portAsString = std::to_string(this->_port);
	int addrStatus = getaddrinfo(NULL, portAsString.c_str(), &hints, &result);
	if (addrStatus != 0) {
		throw SocketServerException("GetAddressInfo - failed: " + addrStatus);
	}
	return result;
}

void WinSockSocket::createSocket(addrinfo* result) {
	this->_listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (_listenSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		throw SocketServerException("CreateSocket - error at socket(): " + WSAGetLastError());
	}
};

void WinSockSocket::bindSocket(addrinfo* result) {
	int bindStatus = bind(this->_listenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (_listenSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		throw SocketServerException("BindSocket - bind failed with error : " + WSAGetLastError());
	}
}

/* Public methods */
bool WinSockSocket::isListening() {
	return this->_listening.load();
}


void WinSockSocket::listen(std::function<void(IClientSocket*)> callback) {
	if (::listen(_listenSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cerr << "Listen - listen failed: " << WSAGetLastError();
		return;
	}
	SOCKET clientSocket = INVALID_SOCKET;
	this->_listening.store(true);

	while (isListening()) {
		// Accept a client socket
		clientSocket = accept(_listenSocket, NULL, NULL);

		if (clientSocket != INVALID_SOCKET) {
			callback(new WinSockClientSocket(clientSocket));
		}
		else {
			std::cerr << "Listen - accept failed: " << WSAGetLastError();
		}
		Sleep(1000);
	}
	return;
}


