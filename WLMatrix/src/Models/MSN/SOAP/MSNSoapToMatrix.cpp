#include "MSNSoapToMatrix.h"
#include "pugixml.hpp"

MatrixCredentials MSNSoapToMatrix::getMatrixCredentials(std::string soapRST2Request) {
        pugi::xml_document doc;
        doc.load_string(soapRST2Request.c_str());
        std::string searchStr = "wsse:UsernameToken/wsse:Username";
        pugi::xpath_node xpathNode = doc.child("s:Envelope").child("s:Header").child("wsse:Security").child("wsse:UsernameToken");
        std::string login = xpathNode.node().child("wsse:Username").child_value();
        std::string password = xpathNode.node().child("wsse:Password").child_value();
        return MatrixCredentials(login, password);
};

std::string MSNSoapToMatrix::getMatrixToken(std::string soapRequestBody){
        pugi::xml_document doc;
        doc.load_string(soapRequestBody.c_str());
        pugi::xpath_node xpathNode = doc.child("soap:Envelope").child("soap:Header").child("ABAuthHeader").child("TicketToken");
        std::string token = xpathNode.node().child_value();
        return token.substr(2, token.length());
};