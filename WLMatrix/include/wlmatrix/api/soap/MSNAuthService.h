#pragma once 
#include "AbstractMSNSoapService.h"

class MSNAuthService : public AbstractMSNSoapService{
    public :
        SoapResponse handleRequest(http_request request) override;
        MSNAuthService();

};
