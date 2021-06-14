#pragma once
#include "IMSNPCommandHandler.h"

class MSNPVER : public IMSNPCommandHandler {
	public:
		std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNPUSR : public IMSNPCommandHandler {
	public :
		std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
	private : 
		std::string handleSHA(std::string commandOrder, std::string email);
		std::string handleSSO();
};

class MSNPCVR : public IMSNPCommandHandler {
	public :
		std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNPUUX : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNPBLP : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNPNG : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNCHG : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNADL : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};

class MSNPEmpty : public IMSNPCommandHandler {
public:
	std::vector<std::string> executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const override;
};


