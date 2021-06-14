#pragma once
#include "AbstractMSNSoapService.h"

/* private */
bool AbstractMSNSoapService::handlersContainsKey(std::string key)
{
    for (auto handler : _handlers)
    {
        if (handler.first._Starts_with(key))
        {
            return true;
        }
    }
    return false;
};

/* public */
bool AbstractMSNSoapService::canHandleRequest(http_request request)
{
    auto requestPath = utility::conversions::to_utf8string(request.absolute_uri().to_string());
    std::string soapAction = "";
    if (request.headers().has(L"SOAPAction"))
    {
        soapAction += "/";
        soapAction = utility::conversions::to_utf8string(request.headers()[L"SOAPAction"]);
    }
    requestPath += soapAction;
    return handlersContainsKey(requestPath);
}