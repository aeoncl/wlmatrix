#include "SOAPEndpointHandlers.h"
#include "MSNSoapToMatrix.h"
#include "MatrixToMSNSoap.h"
#include "AuthResponse.h"
#include "MatrixBackend.h"
#include "ClientInfo.h"
#include <iostream>
#include "MatrixRestServiceException.h"

/**
 * /RST2.srf
 * */
SoapResponse RST2::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository *repo) const
{
        MSNSoapToMatrix msn2mat;
        auto creds = msn2mat.getMatrixCredentials(requestBody);

        MatrixBackend matrix;
        try
        {
                AuthResponse matrixResponse = matrix.authenticate(creds);
                MatrixToMSNSoap mat2msn;
                auto xmlPayload = mat2msn.getRST2Response(matrixResponse, matrixResponse.getUserIdAsStr());
                std::cout << "Response - RST2 : " << xmlPayload << std::endl;
                return SoapResponse(xmlPayload, 200);
        }
        catch (MatrixRestServiceException &e)
        {
                return SoapResponse("", 500);
        }
}

SoapResponse SharingService::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository *repo) const
{
        std::cout << "Test: " << requestBody << std::endl;
        MSNSoapToMatrix msn2mat;
        auto token = msn2mat.getMatrixToken(requestBody);
        auto info = repo->findClientByMatrixToken(token);

        if (soapAction == "http://www.msn.com/webservices/AddressBook/FindMembership")
        {
                
                MatrixBackend matrix(info->getMatrixServerUrl(), token);
                auto matrixResult = matrix.initialSync("", MatrixPresence::Online);

                MatrixToMSNSoap mat2msn;
                auto contentTest = mat2msn.getFindMembershipResponse(matrixResult, info->getMSNLogin());
                return SoapResponse(contentTest, 200);
        }
        return SoapResponse("", 200);
}

SoapResponse AbService::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository *repo) const
{

        std::cout << "Test: " << requestBody << std::endl;
        if (soapAction == "http://www.msn.com/webservices/AddressBook/ABFindContactsPaged")
        {
                MSNSoapToMatrix msn2mat;
                auto token = msn2mat.getMatrixToken(requestBody);
                auto info = repo->findClientByMatrixToken(token);

                MatrixToMSNSoap mat2msn;

                std::string resp = mat2msn.getContactsPagedResponse(info->getMSNLogin());
                std::cout << "Test: " << resp << std::endl;

                return SoapResponse(resp, 200);
        }
        return SoapResponse("", 200);
}

/**
 * any
 * */
SoapResponse SoapEmpty::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository *repo) const
{
        return SoapResponse("", 200);
}