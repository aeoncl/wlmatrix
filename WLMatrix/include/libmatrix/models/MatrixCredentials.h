#pragma once
#include "IJsonSerializable.h"
#include <string>

class MatrixCredentials : public IJsonSerializable {
    private :
        std::wstring _username;
        std::wstring _password;
        std::wstring _url;
        std::wstring _deviceId;
        std::wstring _initialDeviceDisplayName;
    public :
        MatrixCredentials(std::wstring username, std::wstring password,std::wstring initialDeviceName, std::wstring url, std::wstring deviceId);
        MatrixCredentials(std::wstring username, std::wstring password, std::wstring initialDeviceName, std::wstring url);
        MatrixCredentials();
        MatrixCredentials(const MatrixCredentials& obj);
        ~MatrixCredentials();
        std::wstring serializeJson() override;
        std::wstring getUrl();
        std::wstring getDeviceId();
        std::wstring getInitialDeviceDisplayName();
        void setDeviceId(std::wstring deviceId);
        void setInitialDeviceDisplayName(std::wstring initDeviceDisplayName);
};