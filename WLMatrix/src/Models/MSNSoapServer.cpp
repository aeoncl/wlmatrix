#include "MSNSoapServer.h"
#include <functional>
#include <iostream>
using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;
/* Constructor */
MSNSoapServer::MSNSoapServer(ClientInfoRepository& repo) {
    _repo = repo;
	utility::string_t url_utf16 = utility::conversions::to_utf16string("http://127.0.0.1:8080");
	http::uri uri(url_utf16);
	_listener = new http_listener(uri);
}

/* Copystructor */
MSNSoapServer::MSNSoapServer(const MSNSoapServer& obj) {
    this->_repo = obj._repo;
    this->_listener = obj._listener;

}

/* Vaati */
MSNSoapServer::~MSNSoapServer() {
    _listener->close().get();
    delete(_listener);
    std::cout<< "MSNSoapServer Destroyed" << std::endl;
}

void MSNSoapServer::listen() {
    try{
    _listener->open().get();
    _listener->support(std::bind(&MSNSoapServer::onRequestReceveid, this, std::placeholders::_1));
    std::cout << "Soap server listening" << std::endl;
    } catch (...) {
        std::cerr << "Unable to create soap server" << std::endl;
    }
}

void MSNSoapServer::onRequestReceveid(http_request request) {
    //Handle received http request
    http_response response(200);
    response.set_body("Hi", "text/plain");
    request.reply(response);
}
