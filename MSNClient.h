#pragma once
#include <atomic>
#include <thread>
#include <string>
#include <WinSock2.h>


#define DEFAULT_BUFLEN 512


class MSNClient {
	private:
		SOCKET _clientSocket;
		std::atomic<bool> _listening;
		std::thread _thread;
		void send(SOCKET& clientSocket, std::string msg);
	public:
		MSNClient(SOCKET& clientSocket);
		MSNClient(const MSNClient& obj);
		~MSNClient();
		bool isListening() { return _listening.load(); };
		void listen();
};