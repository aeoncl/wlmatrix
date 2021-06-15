#pragma once
#include <string>
#include "MatrixErrorCode.h"
class MatrixErrorResponse
{
private:
    MatrixErrorCode _errorCode;
    std::wstring _error;
    int _retryAfterMs;

public:
    MatrixErrorResponse();
    MatrixErrorResponse(MatrixErrorCode errorCode, std::wstring error);
    MatrixErrorResponse(MatrixErrorCode errorCode, std::wstring error, int retryAfterMs);
    MatrixErrorResponse(MatrixErrorResponse &obj);
    MatrixErrorCode getErrorCode();
    int getRetryAfterMs();
    std::wstring getError();
    void setRetryAfterMs(int retryAfterMs);
    void setError(std::wstring error);
    void setErrorCode(MatrixErrorCode errorCode);

    static MatrixErrorResponse deserializeJson(std::wstring json);
};