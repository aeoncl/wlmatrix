#pragma once
#include <iostream>
#include <exception>
#include <string>
class SocketServerException : public std::exception {
public:
	SocketServerException(const char* msg);
};
