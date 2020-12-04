#pragma once
#include <string>
#include "cpprest/asyncrt_utils.h"
class AuthResponse{
    private:
        std::wstring _userId;
        std::wstring _accessToken;
        std::wstring _homeServer;
        std::wstring _deviceId;
    public:
        std::wstring getUserId(){
            return _userId;
        }
        std::wstring getAccessToken(){
            return _accessToken;
        }
        std::wstring getHomeServer(){
            return _homeServer;
        }
        std::wstring getDeviceId(){
            return _deviceId;
        }
        std::string getUserIdAsStr(){
            return utility::conversions::to_utf8string(_userId);
        }
        std::string getAccessTokenAsStr(){
            return utility::conversions::to_utf8string(_accessToken);
        }
        std::string getHomeServerAsStr(){
            return utility::conversions::to_utf8string(_homeServer);
        }
        std::string getDeviceIdAsStr(){
            return utility::conversions::to_utf8string(_deviceId);
        }
        void setUserId(std::wstring userId){
            _userId = userId;
        }
        void setAccessToken(std::wstring accessToken){
            _accessToken = accessToken;
        }

        void setHomeServer(std::wstring homeServer){
            _homeServer = homeServer;
        }
        
        void setDeviceId(std::wstring deviceId){
            _deviceId = deviceId;
        }

        static AuthResponse deserializeJson(std::string json);



};