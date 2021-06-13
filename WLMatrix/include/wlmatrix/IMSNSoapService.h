#pragma once
#include "cpprest/http_listener.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;

class IMSNSoapService {
    
    public : 
        virtual bool canHandleRequest(http_request request);
        virtual bool handleRequest(http_request request);

