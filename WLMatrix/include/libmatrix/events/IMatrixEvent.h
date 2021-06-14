#pragma once
#include <string>
class IMatrixEvent {
    public :
        virtual void deserializeJson(std::string json);
    
};