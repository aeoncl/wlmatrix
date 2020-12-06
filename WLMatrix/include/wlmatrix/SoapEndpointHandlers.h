#pragma once
#include "ISoapEndpointHandler.h"
class RST2 : public ISoapEndpointHandler {
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const override;
};


class SharingService : public ISoapEndpointHandler {
    private : 
        SoapResponse handleFindMembership(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const;
        SoapResponse handleFindAll(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const;
        SoapResponse handleAddMember(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const;
        SoapResponse handleDeleteMember(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const;
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const override;
};

class AbService : public ISoapEndpointHandler {
    private : 
        SoapResponse handleFindContactsPaged(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const;
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const override;
};


class SoapEmpty : public ISoapEndpointHandler {
	public:
		SoapResponse handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* clientInfo) const override;
};