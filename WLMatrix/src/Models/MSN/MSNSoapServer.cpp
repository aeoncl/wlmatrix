#include "MSNSoapServer.h"
#include <functional>
#include <iostream>
#include "pugixml.hpp"
#include "MatrixBackend.h"
#include "AuthResponse.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;
/* Constructor */
MSNSoapServer::MSNSoapServer(ClientInfoRepository &repo)
{
    _repo = repo;
    http::uri uri(L"http://127.0.0.1:8080");
    auto test = uri.is_port_default();
    _listener = new http_listener(uri);
}

/* Copystructor */
MSNSoapServer::MSNSoapServer(const MSNSoapServer &obj)
{
    this->_repo = obj._repo;
    this->_listener = obj._listener;
}

/* Vaati */
MSNSoapServer::~MSNSoapServer()
{
    _listener->close().get();
    delete (_listener);
    std::cout << "MSNSoapServer Destroyed" << std::endl;
}

void MSNSoapServer::listen()
{
    try
    {
        _listener->open().get();
        _listener->support(methods::GET, std::bind(&MSNSoapServer::onGetRequestReceveid, this, std::placeholders::_1));
        _listener->support(methods::POST, std::bind(&MSNSoapServer::onPostRequestReceveid, this, std::placeholders::_1));
        std::cout << "Soap server listening" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unable to create soap server" << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

void MSNSoapServer::onGetRequestReceveid(http_request request)
{
    //Handle received Gethttp request
    auto wholeUri = utility::conversions::to_utf8string(request.request_uri().to_string());
    auto requestPath = utility::conversions::to_utf8string(request.absolute_uri().to_string());

    std::cout << ">> GET " << wholeUri << std::endl;
    http_response response(200);
    response.set_body("Hi", "text/plain");

    if(requestPath._Starts_with("/config/MsgrConfig.asmx")){
        std::ifstream ifs("D:\\Aeon\\Documents\\repo\\MSNeo\\WLMatrix\\WLMatrix\\data\\xml\\MsgrConfig_response.xml");
        std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        response.set_body(content, "application/soap+xml");
    }

    request.reply(response);

}

void MSNSoapServer::onPostRequestReceveid(http_request request)
{
    //Handle received Post http request
    http_response response(200);
    response.set_body("Hi", "text/plain");
    auto wholeUri = utility::conversions::to_utf8string(request.request_uri().to_string());
    
    auto requestPath = utility::conversions::to_utf8string(request.absolute_uri().to_string());
    std::cout << ">> POST " << wholeUri << std::endl;

        pugi::xml_document doc;
        auto xmlRequest = request.extract_utf8string(true).get();
        std::cout << xmlRequest << std::endl;
        auto parsedXml = doc.load_string(xmlRequest.c_str());

    if (requestPath == "/RST2.srf")
    {
        //TODO move each of those handlers to their separate helper
        std::string searchStr = "wsse:UsernameToken/wsse:Username";
        pugi::xpath_node xpathNode = doc.child("s:Envelope").child("s:Header").child("wsse:Security").child("wsse:UsernameToken");
        std::string login = xpathNode.node().child("wsse:Username").child_value();
        std::string password = xpathNode.node().child("wsse:Password").child_value();

        MatrixCredentials cred(login, password);
        MatrixBackend matrix;
        AuthResponse matrixResponse = matrix.authenticate(cred);

        //TODO set the token & user
        response.set_status_code(200);
        std::ifstream ifs("D:\\Aeon\\Documents\\repo\\MSNeo\\WLMatrix\\WLMatrix\\data\\xml\\RST2_response_success.xml");
        std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        response.set_body(content, "application/soap+xml");
    }
    request.reply(response);
}