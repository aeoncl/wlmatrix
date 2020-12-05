#include "MatrixCredentials.h"
#include "cpprest\json.h"
#include <regex>

using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

    MatrixCredentials::MatrixCredentials(std::string login, std::string password) {
        _password = password;
        parseLogin(login);
    }

    MatrixCredentials::MatrixCredentials() {}
    
    MatrixCredentials::MatrixCredentials(const MatrixCredentials& obj){
        _password = obj._password;
        _port = obj._port;
        _url = obj._url;
        _username =  obj._username;
    }

    MatrixCredentials::~MatrixCredentials(){}

    std::wstring MatrixCredentials::serializeJson() {
        json::value identifier;
        identifier[L"type"] = json::value::string(L"m.id.user");
        identifier[L"user"] = json::value::string(to_utf16string(_username));

        json::value loginPayload;
        loginPayload[L"type"] = json::value::string(L"m.login.password");
        loginPayload[L"identifier"] = identifier;
        loginPayload[L"password"] = json::value::string(to_utf16string(_password));
        loginPayload[L"initial_device_display_name"] = json::value::string(L"WLMatrix");

        return loginPayload.serialize();
    }

    void MatrixCredentials::parseLogin(std::string login) {
        auto matchResults = std::smatch{};
	    bool const hasMatches = std::regex_search(login, matchResults, std::regex("([\\w\\d]*)@([\\w\\d\\.]*)-?(\\d+)?"));

        //Todo make this not suck
	    if (hasMatches) {
		    _username = matchResults[1].str();
            _serverName = matchResults[2].str();
            _port = matchResults[3].str();
            _url = "http://" + _serverName + ":" + _port;
        }
    }