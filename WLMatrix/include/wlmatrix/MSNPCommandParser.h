#pragma once
#include <vector>
#include <string>

class MSNPCommandParser{
    private :
        static bool hasPayload(std::string command);

    public :
        static std::vector<std::string> splitMessage(std::string message);
};