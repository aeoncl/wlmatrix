#pragma once
#include <string>
#include "AuthResponse.h"
#include "SyncResponse.h"
#include "StringUtils.h"


class MatrixToMSNSoap {
    private :
        std::string forgeRST2Token(std::string domain, std::string token, std::string today, std::string tomorrow, int number);
        std::string getAllTokens(std::string token, std::string today, std::string tomorrow);
    public :
        std::string getRST2Response(AuthResponse matrixResponse);
        std::string getFindMembershipResponse(SyncResponse matrixResponse, std::string msnLogin);
};