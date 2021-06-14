#include "MatrixCredentials.h"
#include "cpprest\json.h"
#include <regex>

using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

//Todo remove all MSN related code from here. (login)
MatrixCredentials::MatrixCredentials(std::string login)
{
    _loginString = login;
    parseLogin(login);
}

MatrixCredentials::MatrixCredentials(std::string login, std::string password)
{
    _loginString = login;
    _password = password;
    parseLogin(login);
}

MatrixCredentials::MatrixCredentials(std::string login, std::string password, std::string deviceId)
{
    _loginString = login;
    _password = password;
    _deviceId = deviceId;
    parseLogin(login);
}
MatrixCredentials::MatrixCredentials() {}

MatrixCredentials::MatrixCredentials(const MatrixCredentials &obj)
{
    _password = obj._password;
    _port = obj._port;
    _url = obj._url;
    _username = obj._username;
    _deviceId = obj._deviceId;
    _initialDeviceDisplayName = obj._initialDeviceDisplayName;
}

MatrixCredentials::~MatrixCredentials() {}

std::string MatrixCredentials::getUrl()
{
    return _url;
}
std::string MatrixCredentials::getPort()
{
    return _port;
}

std::string MatrixCredentials::getDeviceId()
{
    return _deviceId;
}

void MatrixCredentials::setDeviceId(std::string deviceId)
{
    _deviceId = deviceId;
}

void MatrixCredentials::setLoginString(std::string loginString)
{
    _loginString = loginString;
}
std::string MatrixCredentials::getLoginString()
{
    return _loginString;
}

void MatrixCredentials::setInitialDeviceDisplayName(std::string initDeviceDisplayName)
{
    _initialDeviceDisplayName = initDeviceDisplayName;
}

std::string MatrixCredentials::getInitialDeviceDisplayName()
{
    return _initialDeviceDisplayName;
}

std::wstring MatrixCredentials::serializeJson()
{
    json::value identifier;
    identifier[L"type"] = json::value::string(L"m.id.user");
    identifier[L"user"] = json::value::string(to_utf16string(_username));

    json::value loginPayload;
    loginPayload[L"type"] = json::value::string(L"m.login.password");
    loginPayload[L"identifier"] = identifier;
    loginPayload[L"password"] = json::value::string(to_utf16string(_password));
    loginPayload[L"initial_device_display_name"] = json::value::string(to_utf16string(_initialDeviceDisplayName));
    if (!_deviceId.empty())
    {
        loginPayload[L"device_id"] = json::value::string(to_utf16string(_deviceId));
    }

    return loginPayload.serialize();
}

void MatrixCredentials::parseLogin(std::string login)
{
    auto matchResults = std::smatch{};
    bool const hasMatches = std::regex_search(login, matchResults, std::regex("([\\w\\d]*)@([\\w\\d\\.]*)-?(\\d+)?"));

    //Todo make this not suck
    if (hasMatches)
    {
        _username = matchResults[1].str();
        _serverName = matchResults[2].str();
        _port = matchResults[3].str();
        _url = "http://" + _serverName + ":" + _port;
    }
}