#include "MSNSoapServer.h"
#include <functional>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

#include "MatrixBackend.h"
#include "AuthResponse.h"
#include "MSNSoapToMatrix.h"
#include "MatrixToMSNSoap.h"
#include "SoapEndpointHandlerFactory.h"
#include "ISoapEndpointHandler.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;
/* Constructor */
MSNSoapServer::MSNSoapServer(ClientInfoRepository *repo)
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

    if (requestPath._Starts_with("/config/MsgrConfig.asmx"))
    {
        std::ifstream ifs("E:\\Nextcloud\\repo\\MSNeo\\WLMatrix\\WLMatrix\\data\\xml\\MsgrConfig_response.xml");
        std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        response.set_body(content, "application/soap+xml");
        ifs.close();
    }

    if (requestPath._Starts_with("/ppcrlconfig.bin"))
    {
        std::ifstream ifs("E:\\Nextcloud\\repo\\MSNeo\\WLMatrix\\WLMatrix\\bin\\WLMatrix\\Debug\\data\\ppcrl\\ppcrlconfig.bin", std::ios::binary);
        std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(ifs), {});

        response.set_body(buffer);
        ifs.close();
    }
    request.reply(response);
}

void MSNSoapServer::onPostRequestReceveid(http_request request)
{
    auto requestPath = utility::conversions::to_utf8string(request.absolute_uri().to_string());

    auto xmlRequestBody = request.extract_utf8string(true).get();
    auto handler = SoapEndpointHandlerFactory::getHandler(requestPath);
    std::string soapAction;
    if (request.headers().has(L"SOAPAction"))
    {
        soapAction = utility::conversions::to_utf8string(request.headers()[L"SOAPAction"]);
    }
    std::cout << ">> POST " << requestPath << " : " << soapAction << std::endl;
    auto soapResponse = handler->handleRequest(xmlRequestBody, soapAction, _repo);

    http_response response(soapResponse.getStatusCode());
    response.set_body(soapResponse.getBody(), "application/soap+xml");
    request.reply(response);
}