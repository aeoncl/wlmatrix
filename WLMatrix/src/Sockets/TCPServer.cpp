#include "TCPServer.h"
#include <string>
#include "WinSockSocket.h"
#include "ISocket.h"
#include <functional>


/* Constructor */
TCPServer::TCPServer(std::string url, int port, ClientInfoRepository* repo) {
	this->_clientRepo = repo;
	this->_port = port;
	this->_listenSocket = new WinSockSocket(url, port);
}

/* Copystructor */
TCPServer::TCPServer(const TCPServer& obj) {
	std::cout << "Copying SocketServer" << std::endl;
	this->_port = obj._port;
	this->_clientRepo = obj._clientRepo;
	this->_listenSocket = obj._listenSocket;
}

/* Vaati */
TCPServer::~TCPServer() {
	std::cout << "Destroying SocketServer" << std::endl;
	delete(_listenSocket);
}

void TCPServer::listen() {
	std::cout << "Server listening on port: " << _port << std::endl;
	this->_listenSocket->listen(std::bind(&TCPServer::onClientConnected, this, std::placeholders::_1));
}

/* Callback */
void TCPServer::onClientConnected(IClientSocket* clientSocket) {
	//create a thread per connected clients
	std::cout << "Client connected successfully!" << std::endl;
	std::thread thread([this, clientSocket] {handleClient(clientSocket); });
	thread.detach();
}

void TCPServer::handleClient(IClientSocket* socket) {}


