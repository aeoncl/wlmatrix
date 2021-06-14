#pragma once
#include <string>

class MSNUtils {
    public :
        static std::string getMatrixUriForMSNUri(std::string msnUri);
        static std::string getMSNUriForMatrixUri(std::string matrixUri);
};