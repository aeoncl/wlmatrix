#pragma once
#include "IMSNSoapService.h"
#include "ISoapEndpointHandler.h"
#include <string>
#include <unordered_map>

class AbstractMSNSoapService : public IMSNSoapService
{
private:
    std::unordered_map<std::string, const ISoapEndpointHandler *> _handlers;
    bool handlersContainsKey(std::string key);

public:
    bool canHandleRequest(http_request request);
};