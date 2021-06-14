#include "AuthResponse.h"
#include "cpprest\json.h"
#include "cpprest/asyncrt_utils.h"

using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

std::wstring AuthResponse::getUserId()
{
    return _userId;
}
std::wstring AuthResponse::getAccessToken()
{
    return _accessToken;
}
std::wstring AuthResponse::getHomeServer()
{
    return _homeServer;
}
std::wstring AuthResponse::getDeviceId()
{
    return _deviceId;
}
std::string AuthResponse::getUserIdAsStr()
{
    return utility::conversions::to_utf8string(_userId);
}
std::string AuthResponse::getAccessTokenAsStr()
{
    return utility::conversions::to_utf8string(_accessToken);
}
std::string AuthResponse::getHomeServerAsStr()
{
    return utility::conversions::to_utf8string(_homeServer);
}
std::string AuthResponse::getDeviceIdAsStr()
{
    return utility::conversions::to_utf8string(_deviceId);
}
void AuthResponse::setUserId(std::wstring userId)
{
    _userId = userId;
}
void AuthResponse::setAccessToken(std::wstring accessToken)
{
    _accessToken = accessToken;
}

void AuthResponse::setHomeServer(std::wstring homeServer)
{
    _homeServer = homeServer;
}

void AuthResponse::setDeviceId(std::wstring deviceId)
{
    _deviceId = deviceId;
}

AuthResponse AuthResponse::deserializeJson(std::string json)
{
    json::value jsonAsObj = json::value::parse(json);
    AuthResponse response;
    response.setUserId(jsonAsObj.at(L"user_id").as_string());
    response.setAccessToken(jsonAsObj.at(L"access_token").as_string());
    response.setHomeServer(jsonAsObj.at(L"home_server").as_string());
    response.setDeviceId(jsonAsObj.at(L"device_id").as_string());
    return response;
}