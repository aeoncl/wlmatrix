#pragma once
#include <unordered_map>
#include "IMSNPCommand.h"
class MSNPCommandFactory {
	private :
		const static std::unordered_map<std::string, const IMSNPCommand*> _commands;
	public : 
		const static IMSNPCommand* getCommand(std::string commandName);
};

