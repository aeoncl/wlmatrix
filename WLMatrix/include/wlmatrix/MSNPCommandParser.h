#pragma once
#include "MSNPCommand.h"
#include <vector>
#include <string>

class MSNPCommandParser{
    private :
        static bool hasPayload(std::string command);

    public :
        static std::vector<MSNPCommand> parseMessage(std::string message);
        static std::vector<std::string> splitMessage(std::string message);
};