#pragma once
#include <functional>
#include "IClientSocket.h"

class ISocket {
	public:
		virtual void listen(std::function<void(IClientSocket*)> callback) {};
		virtual bool isListening() { return false; };
};
