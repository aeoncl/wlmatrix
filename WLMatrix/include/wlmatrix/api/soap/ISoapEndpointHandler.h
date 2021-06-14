#pragma once
#include <vector>
#include <string>
#include "ClientInfoRepository.h"
#include "SoapResponse.h"

class ISoapEndpointHandler {
	public :
		virtual SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const { return SoapResponse(); };
};