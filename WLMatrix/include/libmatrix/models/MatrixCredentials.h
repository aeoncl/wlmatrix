#pragma once
#include "IJsonSerializable.h"
#include <string>

class MatrixCredentials : public IJsonSerializable {
    private :
        std::string _username;
        std::string _password;
        std::string _serverName;
        std::string _loginString;
        std::string _port;
        std::string _url;
        void parseLogin(std::string login);
    public :
        MatrixCredentials(std::string login);
        MatrixCredentials(std::string login, std::string password);
        MatrixCredentials();
        MatrixCredentials(const MatrixCredentials& obj);
        ~MatrixCredentials();
        std::wstring serializeJson() override;
        std::string getUrl();
        std::string getPort();
        void setLoginString(std::string loginString);
        std::string getLoginString();
};