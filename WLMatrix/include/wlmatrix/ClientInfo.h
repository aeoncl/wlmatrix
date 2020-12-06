#pragma once
#include <string>
#include "AuthResponse.h"
class ClientInfo {
	private :
		int _msnDialectVersion;
		std::string _matrixServerUrl;
		std::string _msnLogin;
		AuthResponse _matrixAuthData;

	public :
		ClientInfo();
		ClientInfo(const ClientInfo& obj);
		~ClientInfo();

		int getMSNDialectVersion() { return _msnDialectVersion; };
		void setMSNDialectVersion(int dialectVersion) { _msnDialectVersion = dialectVersion; };

		AuthResponse getMatrixAuthData() { return _matrixAuthData; };
		void setMatrixAuthData(AuthResponse authData) {
			_matrixAuthData = _matrixAuthData;
		};

		void setMatrixServerUrl(std::string url){
			_matrixServerUrl = url;
		};

		std::string getMatrixServerUrl() {
			return _matrixServerUrl;
		};

		std::string getMatrixToken() {
			return _matrixAuthData.getAccessTokenAsStr();
		}

		void setMSNLogin(std::string msnLogin){
			_msnLogin = msnLogin;
		}
		
		std::string getMSNLogin(){
			return _msnLogin;
		}
		

};

