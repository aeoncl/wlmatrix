#pragma once
#include "IClientSocket.h"
#include <WinSock2.h>
#include <atomic>

#define DEFAULT_BUFLEN 512

class WinsockClientSocket : public IClientSocket {
	private :
		SOCKET _socket;
		std::atomic_bool _listening;
	public : 
		WinsockClientSocket(SOCKET socket) : _socket(socket) {};
		WinsockClientSocket(const WinsockClientSocket& obj);
		~WinsockClientSocket();
		void send(std::string) override;
		void receive(std::function<void(std::string)> callback) override;
		bool isListening() override;
};

