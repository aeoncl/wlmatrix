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
}
