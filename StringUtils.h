#pragma once
#include <vector>
#include <string>
class StringUtils
{
	public:
		static std::vector<std::string> split(std::string& string, char separator);
		static std::vector<std::string> splitLines(std::string& string);
		static std::string getStringForShittyBuffer(char chars[], int messageLength);

};

