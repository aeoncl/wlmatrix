#include "StringUtils.h"

std::vector<std::string> StringUtils::split(std::string& string, char separator)
{
	std::vector<std::string> strings;
	std::string remainingString = string;
	std::size_t separatorIndex = remainingString.find(separator);
	while (separatorIndex != std::string::npos) {
		strings.push_back(remainingString.substr(0, separatorIndex));
		remainingString = remainingString.substr(separatorIndex+1, remainingString.length());
		separatorIndex = remainingString.find(separator);
	}
	return strings;
}

std::vector<std::string> StringUtils::splitLines(std::string& string)
{
	return split(string, '\n');
}

std::string StringUtils::getStringForShittyBuffer(char chars[], int arrayLength) {
	chars[arrayLength] = '\0';
	return std::string(chars);
}