#pragma once
#include "ISocket.h"
#include <atomic>
#include <WinSock2.h>
class WinSockSocket : public ISocket {

	private:
		int _port;
		std::atomic_bool _listening;
		SOCKET _listenSocket;
		void createSocket();
		WSADATA* initWinsock();
		addrinfo* getAddressInfo();
		void createSocket(addrinfo* result);
		void bindSocket(addrinfo* result);
	public :
		WinSockSocket(int port);
		WinSockSocket(const WinSockSocket& obj);
		~WinSockSocket();
		void listen(std::function<void(IClientSocket*)> callback) override;
		bool isListening() override;
};

