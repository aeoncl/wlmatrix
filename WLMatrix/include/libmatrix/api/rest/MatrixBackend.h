#pragma once
#include <string>
#include "MatrixCredentials.h"
#include "AuthResponse.h"
#include "MatrixPresence.h"
#include "SyncResponse.h"
#include "WhoAmIResponse.h"

class MatrixBackend {
    private :
        std::wstring _url;
        std::string _token;
        SyncResponse sync(AuthResponse authData, std::wstring url, std::string timeStamp, MatrixPresence status);
    public :
        MatrixBackend();
        MatrixBackend(std::wstring url, std::string token);

        AuthResponse authenticate(MatrixCredentials matrixServer);
        WhoAmIResponse whoami();
        SyncResponse initialSync(std::string timeStamp, MatrixPresence status);
};