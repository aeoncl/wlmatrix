#pragma once
#include "ISoapEndpointHandler.h"
class RST2 : public ISoapEndpointHandler {
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const override;
};


class SharingService : public ISoapEndpointHandler {
    private : 
        SoapResponse handleFindMembership(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const;
        SoapResponse handleFindAll(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const;
        SoapResponse handleAddMember(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const;
        SoapResponse handleDeleteMember(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const;
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const override;
};


class SoapEmpty : public ISoapEndpointHandler {
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfo* clientInfo) const override;
};