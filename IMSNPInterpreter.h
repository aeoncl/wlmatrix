#pragma once
#include <string>
#include <regex>

class MSNClient;

class IMSNPInterpreter {
	public :
		virtual std::string interpretMessage(std::string message, MSNClient& client) const { return ""; };
};