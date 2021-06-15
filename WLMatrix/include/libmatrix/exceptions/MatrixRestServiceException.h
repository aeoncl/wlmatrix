#include <exception>
#include <string>
#include "MatrixErrorResponse.h"
class MatrixRestServiceException : public std::exception
{

private:
    int _httpStatusCode;
    MatrixErrorResponse _errorResponse;

public:
    MatrixRestServiceException(const std::string msg);
    MatrixRestServiceException(const std::string msg, int httpStatusCode);
    MatrixRestServiceException(const std::string msg, int httpStatusCode, MatrixErrorResponse errorResponse);

    int getHttpStatusCode();
    MatrixErrorResponse getErrorResponse();
};