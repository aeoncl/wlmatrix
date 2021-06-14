#pragma once
#include <string>
class SoapResponse{
    private : 
        std::string _body;
        int _statusCode;
    
    public :
        SoapResponse() {};
        SoapResponse(std::string body, int statusCode) : _body(body), _statusCode(statusCode){};
        std::string getBody();
        int getStatusCode();

};