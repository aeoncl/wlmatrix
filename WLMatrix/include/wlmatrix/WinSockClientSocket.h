#pragma once
#include "IClientSocket.h"
#include <WinSock2.h>
#include <atomic>

#define DEFAULT_BUFLEN 512

class WinSockClientSocket : public IClientSocket {
	private :
		SOCKET _socket;
		std::atomic_bool _listening;
		std::string _ip;
	public : 
		WinSockClientSocket(SOCKET socket, std::string ip) : _socket(socket), _ip(ip) {};
		WinSockClientSocket(const WinSockClientSocket& obj);
		~WinSockClientSocket();
		std::string getIpAddress() override;
		void send(std::string) override;
		void receive(std::function<void(std::string)> callback) override;
		bool isListening() override;
};

