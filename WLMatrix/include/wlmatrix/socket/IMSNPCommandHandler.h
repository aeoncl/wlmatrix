#pragma once
#include <string>
#include <regex>
#include "ClientInfo.h"

class MSNClient;

class IMSNPCommandHandler {
	public :
		virtual std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const { return std::vector<std::string>(); };
};