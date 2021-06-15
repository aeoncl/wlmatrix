#include "MatrixBackend.h"
#include "cpprest\http_client.h"
#include "cpprest\json.h"
#include <iostream>
#include "WhoAmIResponse.h"
#include "MatrixRestServiceException.h"
#include "MatrixErrorResponse.h"
using namespace web;
using namespace http;
using namespace json;
using namespace utility;
using namespace conversions;
using namespace client;

MatrixBackend::MatrixBackend(){};
MatrixBackend::MatrixBackend(std::wstring url, std::string token) : _url(url), _token(token){};

/**
 * Throws MatrixRestServiceException
 * */
AuthResponse MatrixBackend::authenticate(MatrixCredentials credentials)
{
    int statusCode = -1;
    MatrixErrorResponse errorResponse;
    try
    {
        http_client client(credentials.getUrl());
        std::wstring test = credentials.serializeJson();
        auto result = client.request(http::methods::POST, L"/_matrix/client/r0/login", credentials.serializeJson(), L"application/json").get();
        statusCode = result.status_code();
        if (statusCode != 200)
        {
            errorResponse = MatrixErrorResponse::deserializeJson(result.extract_utf16string().get());
            throw new MatrixRestServiceException("");
        }
        return AuthResponse::deserializeJson(result.extract_utf8string().get());
    }
    catch (const MatrixRestServiceException &restE)
    {
        throw new MatrixRestServiceException("", statusCode, errorResponse);
    }
    catch (const http_exception &httpE)
    {
        throw MatrixRestServiceException("An error has occured while contacting the server.", statusCode);
    }
    catch (const json_exception &jsonE)
    {
        throw MatrixRestServiceException("Could not deserialize response", statusCode);
    }
}

/**
 * Throws MatrixRestServiceException
 * */
WhoAmIResponse MatrixBackend::whoami()
{
    int statusCode = -1;
    MatrixErrorResponse errorResponse;
    try
    {
        http_client client(_url);
        http_request req(http::methods::GET);
        req.set_request_uri(L"/_matrix/client/r0/account/whoami");
        req.headers().add(L"Authorization", L"Bearer " + to_utf16string(_token));
        auto result = client.request(req).get();
        if (statusCode != 200)
        {
            errorResponse = MatrixErrorResponse::deserializeJson(result.extract_utf16string().get());
            throw new MatrixRestServiceException("");
        }
        return WhoAmIResponse::deserializeJson(result.extract_string().get());
    }
    catch (const MatrixRestServiceException &restE)
    {
        throw new MatrixRestServiceException("", statusCode, errorResponse);
    }
    catch (const http_exception &httpE)
    {
        throw MatrixRestServiceException("An error has occured while contacting the server.", statusCode);
    }
    catch (const json_exception &jsonE)
    {
        throw MatrixRestServiceException("Could not deserialize response", statusCode);
    }
}

/**
 * Throws RestServiceException
 * */
SyncResponse MatrixBackend::initialSync(std::string timeStamp, MatrixPresence status)
{
    int statusCode = -1;
    MatrixErrorResponse errorResponse;
    try
    {
        http_client client(_url);
        http_request req(http::methods::GET);
        req.set_request_uri(L"/_matrix/client/r0/sync");
        req.headers().add(L"Authorization", L"Bearer " + to_utf16string(_token));
        auto result = client.request(req).get();
        if (statusCode != 200)
        {
            errorResponse = MatrixErrorResponse::deserializeJson(result.extract_utf16string().get());
            throw new MatrixRestServiceException("");
        }
        return SyncResponse::deserializeJson(result.extract_utf8string().get());
    }
    catch (const MatrixRestServiceException &restE)
    {
        throw new MatrixRestServiceException("", statusCode, errorResponse);
    }
    catch (const http_exception &httpE)
    {
        throw MatrixRestServiceException("An error has occured while contacting the server.", statusCode);
    }
    catch (const json_exception &jsonE)
    {
        throw MatrixRestServiceException("Could not deserialize response", statusCode);
    }
}
