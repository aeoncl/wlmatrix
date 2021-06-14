#pragma once
#include <vector>
#include <string>
class StringUtils
{
	public:
		static std::vector<std::string> split(std::string& string, char separator);
		static std::vector<std::string> splitLines(std::string& string);
		static std::vector<std::string> splitWords(std::string& string);
		static std::string getStringForShittyBuffer(char chars[], int arrayLength, int messageLength);
		static std::string_view rtrim(std::string_view s);
		static std::string_view ltrim(std::string_view s);
		static std::string_view trim(std::string_view s);
		static void replaceAll(std::string& s, const std::string& toReplace, const std::string& replaceWith);
		static std::string parseBoolean(bool b);
		static std::string toLowerCase(std::string str);
};

