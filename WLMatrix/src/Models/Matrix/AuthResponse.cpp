#include "AuthResponse.h"
#include "cpprest\json.h"
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

    AuthResponse AuthResponse::deserializeJson(std::string json){
        json::value jsonAsObj = json::value::parse(json);
        AuthResponse response;
        response.setUserId(jsonAsObj.at(L"user_id").as_string());
        response.setAccessToken(jsonAsObj.at(L"access_token").as_string());
        response.setHomeServer(jsonAsObj.at(L"home_server").as_string());
        response.setDeviceId(jsonAsObj.at(L"device_id").as_string());
        return response;
    }