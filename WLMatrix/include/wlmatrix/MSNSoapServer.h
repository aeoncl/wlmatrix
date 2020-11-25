#pragma once
#include "ClientInfoRepository.h"
#include "cpprest/http_listener.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;

class MSNSoapServer {
    private:
        http_listener* _listener;
        ClientInfoRepository _repo;
        void onRequestReceveid(http_request request);
    public:
        MSNSoapServer(ClientInfoRepository& repo);
        MSNSoapServer(const MSNSoapServer& obj);
        ~MSNSoapServer();
        void listen();
};