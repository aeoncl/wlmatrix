#include "MatrixBackend.h"
#include "cpprest\http_client.h"
#include "cpprest\json.h"
#include <iostream>
#include "WhoAmIResponse.h"
#include "RestServiceException.h"
using namespace web;
using namespace http;
using namespace json;
using namespace utility;
using namespace conversions;
using namespace client;

MatrixBackend::MatrixBackend(){};
MatrixBackend::MatrixBackend(std::string url, std::string token) : _url(url), _token(token){};

AuthResponse MatrixBackend::authenticate(MatrixCredentials credentials)
{
    http_client client(to_utf16string(credentials.getUrl()));
    auto result = client.request(http::methods::POST, L"/_matrix/client/r0/login", credentials.serializeJson(), L"application/json").get();
    return AuthResponse::deserializeJson(result.extract_utf8string().get());
}

/**
 * Throws RestServiceException
 * */
WhoAmIResponse MatrixBackend::whoami()
{
    try
    {
        http_client client(to_utf16string(_url));
        http_request req(http::methods::GET);
        req.set_request_uri(L"/_matrix/client/r0/account/whoami");
        req.headers().add(L"Authorization", L"Bearer " + to_utf16string(_token));
        auto result = client.request(req).get();
        return WhoAmIResponse::deserializeJson(result.extract_string().get());
    }
    catch (const std::exception &e)
    {
        throw RestServiceException("An error has occured while contacting the server.");
    }
}

SyncResponse MatrixBackend::initialSync(std::string timeStamp, MatrixPresence status)
{
    http_client client(to_utf16string(_url));
    http_request req(http::methods::GET);
    req.set_request_uri(L"/_matrix/client/r0/sync");
    req.headers().add(L"Authorization", L"Bearer " + to_utf16string(_token));
    auto result = client.request(req).get();
    return SyncResponse::deserializeJson(result.extract_utf8string().get());
}
