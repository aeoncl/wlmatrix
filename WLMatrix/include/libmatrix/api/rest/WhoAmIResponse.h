#pragma once
#include <string>

class WhoAmIResponse {
    private :
        std::wstring _userId;
    public :
        std::wstring getUserId();
        
        void setUserId(std::wstring userId);
        
        static WhoAmIResponse deserializeJson(std::wstring json);
};