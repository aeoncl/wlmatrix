#pragma once
#include <string>
#include "MatrixCredentials.h"
#include "AuthResponse.h"
#include "MatrixPresence.h"
#include "SyncResponse.h"
#include "WhoAmIResponse.h"

class MatrixBackend {
    private :
        std::string _url;
        std::string _token;
        SyncResponse sync(AuthResponse authData, std::string url, std::string timeStamp, MatrixPresence status);
    public :
        MatrixBackend(){};
        MatrixBackend(std::string url, std::string token) : _url(url), _token(token){};

        AuthResponse authenticate(MatrixCredentials matrixServer);
        WhoAmIResponse whoami();
        SyncResponse initialSync(std::string timeStamp, MatrixPresence status);
};