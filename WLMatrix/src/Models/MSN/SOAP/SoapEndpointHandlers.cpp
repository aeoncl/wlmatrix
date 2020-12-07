#include "SOAPEndpointHandlers.h"
#include "MSNSoapToMatrix.h"
#include "MatrixToMSNSoap.h"
#include "AuthResponse.h"
#include "MatrixBackend.h"
#include "ClientInfo.h"

/**
 * /RST2.srf
 * */
SoapResponse RST2::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* repo) const{
        MSNSoapToMatrix msn2mat;
        auto creds = msn2mat.getMatrixCredentials(requestBody);

        MatrixBackend matrix;
        AuthResponse matrixResponse = matrix.authenticate(creds);
                
        // try and create responses
        MatrixToMSNSoap mat2msn;
        auto xmlPayload = mat2msn.getRST2Response(matrixResponse);

        return SoapResponse(xmlPayload, 200);
}

SoapResponse SharingService::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* repo) const {
        std::cout << "Test: " << requestBody << std::endl;
        MSNSoapToMatrix msn2mat;
        auto token = msn2mat.getMatrixToken(requestBody);
        auto info = repo->findClientByMatrixToken(token);

        if(soapAction == "http://www.msn.com/webservices/AddressBook/FindMembership"){

                MatrixBackend matrix(info->getMatrixServerUrl(), token);
                auto matrixResult = matrix.initialSync("", MatrixPresence::Online);
                
                MatrixToMSNSoap mat2msn;
                auto contentTest = mat2msn.getFindMembershipResponse(matrixResult);
                std::ifstream ifs("D:\\Aeon\\Documents\\repo\\MSNeo\\WLMatrix\\WLMatrix\\data\\xml\\ab\\find_membership.xml");
                std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
                return SoapResponse(content, 200);
        }
        return SoapResponse("", 200);
}

SoapResponse AbService::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* repo) const {
        std::cout << "Test: " << requestBody << std::endl;
        if(soapAction == "http://www.msn.com/webservices/AddressBook/ABFindContactsPaged"){
                        std::ifstream ifs("D:\\Aeon\\Documents\\repo\\MSNeo\\WLMatrix\\WLMatrix\\data\\xml\\ab\\find_contacts_paged.xml");
                        std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
                        return SoapResponse(content, 200);
        }
        return SoapResponse("", 200);
}

/**
 * any
 * */
SoapResponse SoapEmpty::handleRequest(std::string requestBody, std::string soapAction, ClientInfoRepository* repo) const {
        return SoapResponse("", 200);
}