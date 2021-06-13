#pragma once
#include <string>

class WhoAmIResponse {
    private :
        std::wstring _userId;
    public :
        std::wstring getUserId() {
            return _userId;
        };
        
        void setUserId(std::wstring userId) {
            _userId = userId;
        }
        
        static WhoAmIResponse deserializeJson(std::wstring json);
};