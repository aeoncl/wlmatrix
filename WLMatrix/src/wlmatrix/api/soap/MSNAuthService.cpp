#pragma once
#include "MSNAuthService.h"
#include "SoapResponse.h"

MSNAuthService::MSNAuthService(){
    _supportedUris.push_back("/RST2.srf");
}

SoapResponse MSNAuthService::handleRequest(http_request request){
    SoapResponse response;
    return response;
}