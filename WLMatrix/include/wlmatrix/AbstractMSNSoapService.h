#pragma once
#include "IMSNSoapService.h"
#include <string>
#include <unordered_map>

class AbstractMSNSoapService : public IMSNSoapService
{
private:
    std::unordered_map<std::string, const ISoapEndpointHandler *> _handlers;
    bool handlersContainsKey(std::string key)
    {
        for (auto handler : _handlers)
        {
            if (handler.first._Starts_with(requestPath))
            {
                return true;
            }
        }
        return false;
    };

public:
    bool canHandleRequest(http_request request)
    {
        auto requestPath = utility::conversions::to_utf8string(request.absolute_uri().to_string());
        std::string soapAction = "";
        if (request.headers().has(L"SOAPAction"))
        {
            soapAction += "/"
            soapAction = utility::conversions::to_utf8string(request.headers()[L"SOAPAction"]);
        }
        requestPath += soapAction;
        return handlersContainsKey(requestPath);
    }
