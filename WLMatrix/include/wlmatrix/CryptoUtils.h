#pragma once
#include <string>

class CryptoUtils
{
    public :
    static std::string hashMD5(std::string value);
    static std::string getMD5uuid(std::string value);
};

