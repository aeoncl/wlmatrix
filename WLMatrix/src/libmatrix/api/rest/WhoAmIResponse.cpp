#include "WhoAmIResponse.h"
#include "cpprest/json.h"

using namespace web;

std::wstring WhoAmIResponse::getUserId()
{
    return _userId;
};

void WhoAmIResponse::setUserId(std::wstring userId)
{
    _userId = userId;
}

WhoAmIResponse WhoAmIResponse::deserializeJson(std::wstring json)
{
    json::value jsonAsObj = json::value::parse(json);
    WhoAmIResponse response;
    response.setUserId(jsonAsObj.at(L"user_id").serialize());
    return response;
}