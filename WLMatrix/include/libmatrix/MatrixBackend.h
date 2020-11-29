#pragma once
#include <string>
#include "MatrixCredentials.h"
#include "AuthResponse.h"
class MatrixBackend {
    public :
        AuthResponse authenticate(MatrixCredentials matrixServer);
};