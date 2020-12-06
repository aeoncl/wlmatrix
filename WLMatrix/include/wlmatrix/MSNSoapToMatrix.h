#pragma once
#include <string>
#include "MatrixCredentials.h"
class MSNSoapToMatrix{
    public :
        MatrixCredentials getMatrixCredentials(std::string soapRST2Request);
        std::string getMatrixToken(std::string soapRequestBody);
};