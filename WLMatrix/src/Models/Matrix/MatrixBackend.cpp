#include "MatrixBackend.h"
#include "cpprest\http_client.h"
#include "cpprest\json.h"
#include <iostream>
using namespace web;
using namespace http;
using namespace json;
using namespace utility;
using namespace conversions;
using namespace client;

AuthResponse MatrixBackend::authenticate(MatrixCredentials credentials){

    http_client client(to_utf16string(credentials.getUrl()));
    auto result = client.request(http::methods::POST, L"/_matrix/client/r0/login", credentials.serializeJson(), L"application/json").get();
    return AuthResponse::deserializeJson(result.extract_utf8string().get());
}

SyncResponse MatrixBackend::initialSync(std::string timeStamp, MatrixPresence status){
    http_client client(to_utf16string(_url));
    http_request req(http::methods::GET);
    req.set_request_uri(L"/_matrix/client/r0/sync");
    req.headers().add(L"Authorization", L"Bearer " + to_utf16string(_token));
    auto result = client.request(req).get();
    return SyncResponse::deserializeJson(result.extract_utf8string().get());
}



