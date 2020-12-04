#pragma once
#include <string>
#include "AuthResponse.h"
#include "pugixml.hpp"

class MatrixToMSNSoap{
    private :
        std::string forgeRST2Token(std::string domain, std::string token, std::string today, std::string tomorrow, int number);
        std::string getAllTokens(std::string token, std::string today, std::string tomorrow);
    public :
        std::string getRST2Response(AuthResponse matrixResponse);
};