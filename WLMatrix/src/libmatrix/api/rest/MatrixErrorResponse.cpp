#pragma once
#include "MatrixErrorResponse.h"
#include "cpprest/json.h"
#include "magic_enum.hpp"
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

MatrixErrorResponse::MatrixErrorResponse()
{
    _retryAfterMs = -1;
};
MatrixErrorResponse::MatrixErrorResponse(MatrixErrorCode errorCode, std::wstring error) : MatrixErrorResponse()
{
    _errorCode = errorCode;
    error = _error;
};

MatrixErrorResponse::MatrixErrorResponse(MatrixErrorCode errorCode, std::wstring error, int retryAfterMs) : MatrixErrorResponse(errorCode, error)
{
    _retryAfterMs = retryAfterMs;
};

MatrixErrorResponse::MatrixErrorResponse(MatrixErrorResponse &obj)
{
    _errorCode = obj._errorCode,
    _error = obj._error;
    _retryAfterMs = obj._retryAfterMs;
};

MatrixErrorCode MatrixErrorResponse::getErrorCode()
{
    return _errorCode;
};
std::wstring MatrixErrorResponse::getError()
{
    return _error;
};
int MatrixErrorResponse::getRetryAfterMs()
{
    return _retryAfterMs;
};

void MatrixErrorResponse::setRetryAfterMs(int retryAfterMs)
{
    _retryAfterMs = retryAfterMs;
};

void MatrixErrorResponse::setError(std::wstring error)
{
    _error = error;
};

void MatrixErrorResponse::setErrorCode(MatrixErrorCode errorCode)
{
    _errorCode = errorCode;
};

MatrixErrorResponse MatrixErrorResponse::deserializeJson(std::wstring json)
{

    json::value jsonAsObj = json::value::parse(json);
    std::wstring errCode = jsonAsObj.at(L"errcode").as_string();
    std::wstring error = jsonAsObj.at(L"error").as_string();
    auto castedErrorCode = magic_enum::enum_cast<MatrixErrorCode>(utf16_to_utf8(errCode));

    MatrixErrorResponse response;
    if(castedErrorCode.has_value()) {
        response.setErrorCode(castedErrorCode.value());
    }
    response.setError(error);

    if(jsonAsObj.has_integer_field(L"retry_after_ms")) {
        int retryAfterMs = jsonAsObj.at(L"retry_after_ms").as_integer();
        response.setRetryAfterMs(retryAfterMs);
    }

    return response;
}