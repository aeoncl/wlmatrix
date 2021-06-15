#pragma once
#include "IMSNSoapService.h"
#include "ISoapEndpointHandler.h"
#include <string>
#include <vector>

class AbstractMSNSoapService : public IMSNSoapService
{

private:
    bool supportedUrisContains(std::string uri);

protected : 
    AbstractMSNSoapService(){};
    std::vector<std::string> _supportedUris;

public:

    bool canHandleRequest(http_request request) override;
};