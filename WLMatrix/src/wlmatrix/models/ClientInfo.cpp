#include "ClientInfo.h"
#include <iostream>
		ClientInfo::ClientInfo(){

        };

		ClientInfo::ClientInfo(const ClientInfo& obj){
            _matrixToken = obj._matrixToken;
            _matrixServerUrl = obj._matrixServerUrl;
            _msnDialectVersion = obj._msnDialectVersion;
            _msnLogin = obj._msnLogin;
        };

		ClientInfo::~ClientInfo(){
            std::cout << "ClientInfo Destroyed" << std::endl;
        };