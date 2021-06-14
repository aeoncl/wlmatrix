#pragma once
#include <unordered_map>
#include "IMSNPCommandHandler.h"
class MSNPCommandHandlerFactory {
	private :
		const static std::unordered_map<std::string, const IMSNPCommandHandler*> _commands;
	public : 
		const static IMSNPCommandHandler* getCommand(std::string commandName);
};

