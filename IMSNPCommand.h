#pragma once
#include <string>
#include <regex>

class MSNClient;

class IMSNPCommand {
	public :
		virtual std::vector<std::string> executeCommand(std::string message, MSNClient& client, int dialectVersion) const { return std::vector<std::string>(); };
};