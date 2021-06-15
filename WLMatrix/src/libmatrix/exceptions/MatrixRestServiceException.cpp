#pragma once
#include "MatrixRestServiceException.h"
#include "MatrixErrorResponse.h"

MatrixRestServiceException::MatrixRestServiceException(const std::string msg) : exception(msg.c_str()){};

MatrixRestServiceException::MatrixRestServiceException(const std::string msg, int httpStatusCode) : MatrixRestServiceException(msg)
{
    _httpStatusCode = httpStatusCode;
};

MatrixRestServiceException::MatrixRestServiceException(const std::string msg, int httpStatusCode, MatrixErrorResponse errorResponse) : MatrixRestServiceException(msg, httpStatusCode)
{
    _errorResponse = errorResponse;
};

int MatrixRestServiceException::getHttpStatusCode()
{
    return _httpStatusCode;
};
MatrixErrorResponse MatrixRestServiceException::getErrorResponse()
{
    return _errorResponse;
};
