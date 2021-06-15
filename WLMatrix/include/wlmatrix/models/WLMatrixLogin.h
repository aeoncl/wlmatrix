#pragma once
#include <string>

/**
 * Represents and parses WLMatrix login string :
 * name@matrixServer-port (if no port is here, defaults to https:443)
 * TODO HANDLE HTTPS FLAG
 * */
class WLMatrixLogin
{
private:
    std::wstring _loginString;
    std::wstring _username;
    std::wstring _serverName;
    int _port;
    bool _https;
    void parseLogin(std::string loginString);

public:
    WLMatrixLogin(std::string loginString);
    WLMatrixLogin(const WLMatrixLogin &obj);
    std::wstring getUsername();
    std::wstring getServerName();
    int getPort();
    bool isHTTPS();
    std::wstring getTargetUrl();
};