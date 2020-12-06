#include "ClientInfo.h"
#include <iostream>
		ClientInfo::ClientInfo(){

        };

		ClientInfo::ClientInfo(const ClientInfo& obj){
            _matrixAuthData = obj._matrixAuthData;
            _matrixServerUrl = obj._matrixServerUrl;
            _msnDialectVersion = obj._msnDialectVersion;
            _msnLogin = obj._msnLogin;
        };

		ClientInfo::~ClientInfo(){
            std::cerr << "ClientInfo Destroyed";
        };