#include "MSNPCommandHandlerFactory.h"
#include "MSNPCommandHandlers.h"

const IMSNPCommandHandler* MSNPCommandHandlerFactory::getCommand(std::string commandName){
	try {
		auto test = _commands.at(commandName);
		return test;
	}
	catch (...) {
		return _commands.at("UUX");
	}
}

const std::unordered_map<std::string, const IMSNPCommandHandler*> MSNPCommandHandlerFactory::_commands = {
  {"VER", new MSNPVER()},
  {"USR", new MSNPUSR()},
  {"CVR", new MSNPCVR()},
  {"UUX", new MSNPUUX()},
  {"BLP", new MSNPBLP()},
  {"EMPTY", new MSNPBLP()}
};
