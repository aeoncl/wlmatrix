#include "StringUtils.h"
#include <sstream> 
#include <string_view>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string.hpp>
#include <locale>
#include <codecvt>
#include <string>

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

std::vector<std::string> StringUtils::splitWords(std::string& string) {
	auto stringAppend = string + " ";
	return split(stringAppend, ' ');
}

std::vector<std::string> StringUtils::splitLines(std::string& string) {
	auto result = std::vector<std::string>{};
    auto ss = std::stringstream{string};

    for (std::string line; std::getline(ss, line, '\n');)
        result.push_back((std::string) rtrim(line));

    return result;
}

std::string StringUtils::getStringForShittyBuffer(char chars[], int arrayLength, int messageLength) {
	std::string out;
	if (arrayLength <= messageLength) {
		char* temp = new char[messageLength+1];
		std::copy(chars, chars + messageLength, temp);
		temp[messageLength+1] = '\0';
		out = std::string(temp);
	}
	else {
		chars[messageLength] = '\0';
		out = std::string(chars);
	}
	return out;
}

std::string_view StringUtils::ltrim(std::string_view s)
{
    s.remove_prefix(std::distance(s.cbegin(), std::find_if(s.cbegin(), s.cend(),
         [](int c) {return !std::isspace(c);})));

    return s;
}

std::string_view StringUtils::rtrim(std::string_view s)
{
    s.remove_suffix(std::distance(s.crbegin(), std::find_if(s.crbegin(), s.crend(),
        [](int c) {return !std::isspace(c);})));

    return s;
}

std::string_view StringUtils::trim(std::string_view s)
{
    return ltrim(rtrim(s));
}

void StringUtils::replaceAll(std::string& s, const std::string& toReplace, const std::string& replaceWith)
{
	boost::algorithm::replace_all(s, toReplace, replaceWith);
}

std::string StringUtils::parseBoolean(bool b)
{
    std::stringstream converter;
    converter << std::boolalpha << b;   // flag boolalpha calls converter.setf(std::ios_base::boolalpha)
    return converter.str();
}


std::string StringUtils::toLowerCase(std::string str) {
	std::string copy = str;
	boost::algorithm::to_lower(copy);
	return copy;
}

std::wstring StringUtils::convertToWString(std::string string) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(string);
}

std::string StringUtils::convertToString(std::wstring wstring) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(wstring);
}
