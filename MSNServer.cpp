#include "MSNServer.h"
#include <string>
#include "WinSockSocket.h"
#include "ISocket.h"
#include <functional>

#pragma comment(lib, "Ws2_32.lib")

/* Constructor */
MSNServer::MSNServer(int port) {
	//TODO get the handshake interpreter from the factory
	this->_port = port;
	this->_listenSocket = new WinSockSocket(port);
}

/* Copystructor */
MSNServer::MSNServer(const MSNServer& obj) {
	std::cout << "Copying SocketServer\n";
	this->_port = obj._port;
	this->_listenSocket = obj._listenSocket;
}

/* Destructor */
MSNServer::~MSNServer() {
	std::cout << "Destroying SocketServer\n";
	delete(_listenSocket);
}

void MSNServer::listen() {
	std::cout << "Server listening on port: " << _port << "\n";
	this->_listenSocket->listen(std::bind(&MSNServer::onClientConnected, this, std::placeholders::_1));
}

/* Callback */
void MSNServer::onClientConnected(IClientSocket* clientSocket) {
	//create a thread per connected clients
	std::cout << "Client connected successfully!\n";
	std::thread thread([this, clientSocket] {handleClient(clientSocket); });
	thread.detach();
}

void MSNServer::handleClient(IClientSocket* socket) {
	//ran in another thread
	std::cout << "Started Client thread.\n";
	std::shared_ptr<MSNClient> client = std::make_shared<MSNClient>(socket);
	this->_clients.push_back(client);
	client->listen();
	//when the client don't listen anymore
	eraseClient(client);
	std::cout << "Clients count : " << _clients.size() << "\n";
}

void MSNServer::eraseClient(std::shared_ptr<MSNClient> client) {
	auto findResult = std::find(_clients.begin(), _clients.end(), client);
	if (findResult != _clients.end()) {
		//found
		_clients.erase(findResult);
	}
}


