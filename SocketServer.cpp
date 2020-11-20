#include "SocketServer.h"
#include <string>
#pragma comment(lib, "Ws2_32.lib")

/* Constructor */
SocketServer::SocketServer(int port) {
	this->_port = port;
	this->_listenSocket = INVALID_SOCKET;
	try {
		this->createServer();
	} catch (SocketServerException& e) {
		throw;
	}
}

/* Copystructor */
SocketServer::SocketServer(const SocketServer& obj) {
	std::cout << "Copying SocketServer\n";
	this->_port = obj._port;
	this->_listenSocket = obj._listenSocket;
}

/* Destructor */
SocketServer::~SocketServer() {
	std::cout << "Destroying SocketServer\n";
	this->stop();
	closesocket(_listenSocket);
	WSACleanup();
}

/* Private methods */
void SocketServer::createServer() {
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

WSADATA* SocketServer::initWinsock() {
	WORD wsVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	int wsStatus = WSAStartup(wsVersion, &wsaData);
	if (wsStatus != 0) {
		throw SocketServerException("InitWinSocket - Cannot initialize winsock");
	}
	return &wsaData;
}

addrinfo* SocketServer::getAddressInfo() {
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

void SocketServer::createSocket(addrinfo* result) {
	this->_listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (_listenSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		throw SocketServerException("CreateSocket - error at socket(): " + WSAGetLastError());
	}
};

void SocketServer::bindSocket(addrinfo* result) {
	int bindStatus = bind(this->_listenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (_listenSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		throw SocketServerException("BindSocket - bind failed with error : " + WSAGetLastError());
	}
}

int SocketServer::listen(SOCKET listenSocket) {
	if (::listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cerr << "Listen - listen failed: " << WSAGetLastError();
		return -1;
	}
	SOCKET clientSocket = INVALID_SOCKET;

	while (isListening()) {
		// Accept a client socket
		clientSocket = accept(listenSocket, NULL, NULL);

		if (clientSocket != INVALID_SOCKET) {
			std::cout << "Client connected successfully\n";
			std::thread([this, clientSocket] { handleClient(clientSocket); }).detach();
		}
		else {
			std::cerr << "Listen - accept failed: " << WSAGetLastError();
		}
		Sleep(1000);
	}
	return 0;
}

void SocketServer::handleClient(SOCKET socket) {
	auto client = MSNClient(socket);
	client.listen();
}

/* Public methods */
bool SocketServer::isListening() {
	return this->_listening.load();
}

void SocketServer::listen() {
	this->_listening.store(true);
	int result = this->listen(this->_listenSocket);
	if (result != -1) {
		throw SocketServerException("Listen - listen failed with error: " + WSAGetLastError());
	}
}

void SocketServer::listenAsync() {
	this->_listening.store(true);
	std::thread thread([this] {listen(_listenSocket);});
	thread.detach();
}

void SocketServer::stop() {
	this->_listening.store(false);
}

