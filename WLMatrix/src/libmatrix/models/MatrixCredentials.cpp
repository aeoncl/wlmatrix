#include "MatrixCredentials.h"
#include "cpprest\json.h"
#include <regex>

using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

MatrixCredentials::MatrixCredentials(std::wstring username, std::wstring password,std::wstring initialDeviceName, std::wstring url, std::wstring deviceId) : MatrixCredentials(username, password, initialDeviceName, url)
{
    _deviceId = deviceId;
}

MatrixCredentials::MatrixCredentials(std::wstring username, std::wstring password, std::wstring initialDeviceName, std::wstring url)
{
    _username = username;
    _password = password;
    _initialDeviceDisplayName = initialDeviceName;
    _url = url;

}
MatrixCredentials::MatrixCredentials() {}

MatrixCredentials::MatrixCredentials(const MatrixCredentials &obj)
{
    _password = obj._password;
    _url = obj._url;
    _username = obj._username;
    _deviceId = obj._deviceId;
    _initialDeviceDisplayName = obj._initialDeviceDisplayName;
}

MatrixCredentials::~MatrixCredentials() {}

std::wstring MatrixCredentials::getUrl()
{
    return _url;
}

std::wstring MatrixCredentials::getDeviceId()
{
    return _deviceId;
}

void MatrixCredentials::setDeviceId(std::wstring deviceId)
{
    _deviceId = deviceId;
}

void MatrixCredentials::setInitialDeviceDisplayName(std::wstring initDeviceDisplayName)
{
    _initialDeviceDisplayName = initDeviceDisplayName;
}

std::wstring MatrixCredentials::getInitialDeviceDisplayName()
{
    return _initialDeviceDisplayName;
}

std::wstring MatrixCredentials::serializeJson()
{
    json::value identifier;
    identifier[L"type"] = json::value::string(L"m.id.user");
    identifier[L"user"] = json::value::string(_username);

    json::value loginPayload;
    loginPayload[L"type"] = json::value::string(L"m.login.password");
    loginPayload[L"identifier"] = identifier;
    loginPayload[L"password"] = json::value::string(_password);
    loginPayload[L"initial_device_display_name"] = json::value::string(_initialDeviceDisplayName);
    if (!_deviceId.empty())
    {
        loginPayload[L"device_id"] = json::value::string(_deviceId);
    }

    return loginPayload.serialize();
}