#pragma once
#include "IJsonSerializable.h"
#include <string>

class MatrixCredentials : public IJsonSerializable {
    private :
        std::string _username;
        std::string _password;
        std::string _url;
        std::string _port;
        void parseLogin(std::string login);
    public :
        MatrixCredentials(std::string login, std::string password);
        MatrixCredentials();
        MatrixCredentials(const MatrixCredentials& obj);
        ~MatrixCredentials();
        std::wstring serializeJson() override;
        std::string getUrl() {
            return _url;
        }
        std::string getPort() {
            return _port;
        }
};