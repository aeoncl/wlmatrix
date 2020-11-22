#pragma once
#include "IMSNPCommand.h"

class MSNPVER : public IMSNPCommand {
	public:
		std::vector<std::string> executeCommand(std::string message, MSNClient& client, int dialectVersion) const override;
};

class MSNPUSR : public IMSNPCommand {
	public :
		std::vector<std::string> executeCommand(std::string message, MSNClient& client, int dialectVersion) const override;
};

class MSNPCVR : public IMSNPCommand {
	public :
		std::vector<std::string> executeCommand(std::string message, MSNClient& client, int dialectVersion) const override;
};

class MSNPUUX : public IMSNPCommand {
public:
	std::vector<std::string> executeCommand(std::string message, MSNClient& client, int dialectVersion) const override;
};


