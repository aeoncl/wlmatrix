#pragma once
#include <string>
#include "MatrixCredentials.h"
#include "AuthResponse.h"
#include "MatrixPresence.h"
#include "SyncResponse.h"
class MatrixBackend {
    private :
        SyncResponse sync(AuthResponse authData, std::string url, std::string timeStamp, MatrixPresence status);
    public :
        AuthResponse authenticate(MatrixCredentials matrixServer);
        SyncResponse initialSync(AuthResponse authData, std::string url, std::string timeStamp, MatrixPresence status);
};