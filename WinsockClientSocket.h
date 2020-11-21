#pragma once
#include "IClientSocket.h"
#include <WinSock2.h>
#include <atomic>

#define DEFAULT_BUFLEN 512

class WinSockClientSocket : public IClientSocket {
	private :
		SOCKET _socket;
		std::atomic_bool _listening;
	public : 
		WinSockClientSocket(SOCKET socket) : _socket(socket) {};
		WinSockClientSocket(const WinSockClientSocket& obj);
		~WinSockClientSocket();
		void send(std::string) override;
		void receive(std::function<void(std::string)> callback) override;
		bool isListening() override;
};

