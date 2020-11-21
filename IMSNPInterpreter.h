#pragma once
#include <string>
#include <regex>
class IMSNPInterpreter {
	public :
		virtual std::string interpretMessage(std::string message) { return ""; };

};