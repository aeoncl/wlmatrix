#pragma once
#include <string>
class AuthResponse{
    private:
        std::wstring _userId;
        std::wstring _accessToken;
        std::wstring _homeServer;
        std::wstring _deviceId;
    public:
        std::wstring getUserId();
        std::wstring getAccessToken();
        std::wstring getHomeServer();
        std::wstring getDeviceId();
        std::string getUserIdAsStr();
        std::string getAccessTokenAsStr();
        std::string getHomeServerAsStr();
        std::string getDeviceIdAsStr();
        void setUserId(std::wstring userId);
        void setAccessToken(std::wstring accessToken);
        void setHomeServer(std::wstring homeServer);
        void setDeviceId(std::wstring deviceId);
        
        static AuthResponse deserializeJson(std::string json);



};