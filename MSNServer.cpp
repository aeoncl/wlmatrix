#include "MSNServer.h"
#include <string>
#include "WinSockSocket.h"
#include "ISocket.h"
#include <functional>

/* Constructor */
MSNServer::MSNServer(int port, ClientRepository& repo) {
	this->_clientRepo = repo;
	this->_port = port;
	this->_listenSocket = new WinSockSocket(port);
}

/* Copystructor */
MSNServer::MSNServer(const MSNServer& obj) {
	std::cout << "Copying SocketServer" << std::endl;
	this->_port = obj._port;
	this->_clientRepo = obj._clientRepo;
	this->_listenSocket = obj._listenSocket;
}

/* Destructor */
MSNServer::~MSNServer() {
	std::cout << "Destroying SocketServer" << std::endl;
	delete(_listenSocket);
}

void MSNServer::listen() {
	std::cout << "Server listening on port: " << _port << std::endl;
	this->_listenSocket->listen(std::bind(&MSNServer::onClientConnected, this, std::placeholders::_1));
}

/* Callback */
void MSNServer::onClientConnected(IClientSocket* clientSocket) {
	//create a thread per connected clients
	std::cout << "Client connected successfully!" << std::endl;
	std::thread thread([this, clientSocket] {handleClient(clientSocket); });
	thread.detach();
}

void MSNServer::handleClient(IClientSocket* socket) {
	//ran in another thread
	std::cout << "Started Client thread." << std::endl;
	auto client = std::make_shared<MSNClient>(socket);
	this->_clientRepo.addClient(client);
	client->listen();
	//when the client don't listen anymore	
	this->_clientRepo.removeClient(client);
	std::cout << "Clients count : " << _clientRepo.getClientCount() << std::endl;
}


