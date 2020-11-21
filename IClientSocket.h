#pragma once
#include <functional>

class IClientSocket {
	public:
		virtual void receive(std::function<void(std::string)> callback) {};
		virtual void send(std::string) {};
		virtual bool isListening() { return false; };

};
