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
        std::string _deviceId;
        std::string _initialDeviceDisplayName;
        void parseLogin(std::string login);
    public :
        MatrixCredentials(std::string login);
        MatrixCredentials(std::string login, std::string password);
        MatrixCredentials(std::string login, std::string password, std::string deviceId);
        MatrixCredentials();
        MatrixCredentials(const MatrixCredentials& obj);
        ~MatrixCredentials();
        std::wstring serializeJson() override;
        std::string getUrl();
        std::string getPort();
        std::string getDeviceId();
        std::string getInitialDeviceDisplayName();
        void setDeviceId(std::string deviceId);
        void setInitialDeviceDisplayName(std::string initDeviceDisplayName);
        void setLoginString(std::string loginString);
        std::string getLoginString();
};