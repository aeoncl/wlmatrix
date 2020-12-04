#pragma once
#include <vector>
#include <string>
#include "ClientInfo.h"
#include "SoapResponse.h"

class ISoapEndpointHandler {
	public :
		virtual SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const { return SoapResponse(); };
};