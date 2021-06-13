#include "MSNPCommandParser.h"
#include "StringUtils.h"
#include <regex>
#include <iostream>

bool MSNPCommandParser::hasPayload(std::string command){
    return true;
}

/* Splits invidual commands using fancy regex magic */
std::vector<std::string> MSNPCommandParser::splitMessage(std::string message) {
        std::vector<std::string> commands;

        //std::cout << message << std::endl;

        auto lines = StringUtils::splitLines(message);
        commands.push_back(lines[0]);
        for(int i = 1; i < lines.size(); i++) {
           auto current = lines[i];
           auto previous = lines[i-1];
           if(current.at(0) == '<'){
               //This is a payload
               int lastSpaceIndex = previous.find_last_of(' ');
               auto payloadSize = previous.substr(lastSpaceIndex+1, previous.length() - lastSpaceIndex);
               auto payloadSizeAsInt = std::stoi(payloadSize);
               auto payload = current.substr(0, payloadSizeAsInt);
               auto other = current.substr(payloadSizeAsInt, current.length() - payloadSizeAsInt);
               commands.back().append(payload);
               if(other.size() > 0){
                    commands.push_back(other);
               }
           } else {
               commands.push_back(current);
           }
        }
        return commands;
}