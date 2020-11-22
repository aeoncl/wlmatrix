#include "MSNPCommandFactory.h"
#include "MSNPCommands.h"

const IMSNPCommand* MSNPCommandFactory::getCommand(std::string commandName){
	auto test = _commands.at(commandName);
	return test;
}

const std::unordered_map<std::string, const IMSNPCommand*> MSNPCommandFactory::_commands = {
  {"VER", new MSNPVER()},
  {"USR", new MSNPUSR()},
  {"CVR", new MSNPCVR()},
  {"UUX", new MSNPUUX()}
};
