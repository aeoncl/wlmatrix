#include "SOAPEndpointHandlers.h"
#include "MSNSoapToMatrix.h"
#include "MatrixToMSNSoap.h"
#include "AuthResponse.h"
#include "MatrixBackend.h"
#include "ClientInfo.h"

/**
 * /RST2.srf
 * */
SoapResponse RST2::handleRequest(std::string requestBody, std::string soapAction, ClientInfo* info) const{
        MSNSoapToMatrix msn2mat;
        auto creds = msn2mat.getMatrixCredentials(requestBody);

        MatrixBackend matrix;
        AuthResponse matrixResponse = matrix.authenticate(creds);
        // try and create responses
        MatrixToMSNSoap mat2msn;
        auto xmlPayload = mat2msn.getRST2Response(matrixResponse);

        return SoapResponse(xmlPayload, 200);
}

SoapResponse SharingService::handleRequest(std::string requestBody, std::string soapAction, ClientInfo* info) const {
        std::cout << "Test: " << requestBody << std::endl;
        return SoapResponse("", 200);

}

/**
 * any
 * */
SoapResponse SoapEmpty::handleRequest(std::string requestBody, std::string soapAction, ClientInfo* info) const {
        return SoapResponse("", 200);
}