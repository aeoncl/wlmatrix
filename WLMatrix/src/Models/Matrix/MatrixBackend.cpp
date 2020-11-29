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

    http_client client(to_utf16string("http://" + credentials.getUrl() + ":" + credentials.getPort()));


    std::cout << "JSON : " << "testUTF8" << std::endl;
    auto result = client.request(http::methods::POST, L"/_matrix/client/r0/login", credentials.serializeJson(), L"application/json").get();
    return AuthResponse::deserializeJson(result.extract_utf8string().get());
}
