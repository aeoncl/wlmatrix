#pragma once
#include <string>

class IJsonSerializable {
    public :
        virtual std::wstring serializeJson() {return L"";};
};