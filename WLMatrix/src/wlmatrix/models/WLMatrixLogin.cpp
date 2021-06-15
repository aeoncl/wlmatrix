#pragma once
#include "WLMatrixLogin.h"
#include <string>
#include <regex>
#include "StringUtils.h"

WLMatrixLogin::WLMatrixLogin(std::string loginString)
{
    parseLogin(loginString);
    _https = false; //TODO CHANGE THIS
};

WLMatrixLogin::WLMatrixLogin(const WLMatrixLogin &obj)
{
    _loginString = obj._loginString;
    _username = obj._username;
    _serverName = obj._serverName;
    _port = obj._port;
    _https = obj._https;
}

/*private */

void WLMatrixLogin::parseLogin(std::string loginString)
{
    auto matchResults = std::smatch{};
    bool const hasMatches = std::regex_search(loginString, matchResults, std::regex("([\\w\\d]*)@([\\w\\d\\.]*)-?(\\d+)?"));
    if (hasMatches)
    {
        _username = StringUtils::convertToWString(matchResults[1].str());
        _serverName = StringUtils::convertToWString(matchResults[2].str());
        if(matchResults.length() >= 3){
            _port = std::stoi(matchResults[3].str());
        }
    }
};

/* public */
std::wstring WLMatrixLogin::getUsername()
{
    return _username;
};
std::wstring WLMatrixLogin::getServerName()
{
    return _serverName;
};
int WLMatrixLogin::getPort()
{
    return _port;
};

bool WLMatrixLogin::isHTTPS()
{
    return _https;
}

std::wstring WLMatrixLogin::getTargetUrl()
{

    std::wstring url = L"https://";
    if (!_https)
    {
        url = L"http://";
    }
    url += _serverName;
    if (_port != 0)
    {
        url += L":" + std::to_wstring(_port);
    }
    return url;
};
