#include "SocketServer.h"
#include <string>
#include "WinSockSocket.h"
#include "ISocket.h"
#include <functional>

#pragma comment(lib, "Ws2_32.lib")

/* Constructor */
SocketServer::SocketServer(int port) {
	this->_port = port;
	this->_listenSocket = new WinSockSocket(port);
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
	delete(_listenSocket);
}

void SocketServer::listen() {
	std::cout << "Server listening on port: " << _port << "\n";
	this->_listenSocket->listen(std::bind(&SocketServer::onClientConnected, this, std::placeholders::_1));
}

/* Callback */
void SocketServer::onClientConnected(IClientSocket* clientSocket) {
	//create a thread per connected clients
	std::cout << "Client connected callback!\n";
	std::thread thread([this, clientSocket] {handleClient(clientSocket); });
	thread.detach();
}

void SocketServer::handleClient(IClientSocket* socket) {
	//ran in another thread
	std::cout << "Started Client thread.\n";
	std::shared_ptr<MSNClient> client = std::make_shared<MSNClient>(socket);
	this->_clients.push_back(client);
	client->listen();
	//when the client don't listen anymore
	eraseClient(client);
	std::cout << "clients size : " << _clients.size() << "\n";
}

void SocketServer::eraseClient(std::shared_ptr<MSNClient> client) {
	auto findResult = std::find(_clients.begin(), _clients.end(), client);
	if (findResult != _clients.end()) {
		//found
		_clients.erase(findResult);
	}
}


