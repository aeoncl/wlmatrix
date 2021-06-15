#pragma once
#include "cpprest/http_listener.h"
#include "SoapResponse.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;

class IMSNSoapService {
    protected : 
        IMSNSoapService(){};
    public : 
        virtual bool canHandleRequest(http_request request) {return false;};
        virtual SoapResponse handleRequest(http_request request) {return SoapResponse();};

};