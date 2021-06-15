#pragma once
#include <string>
#include "AuthResponse.h"
class ClientInfo {
	private :
		int _msnDialectVersion;
		std::wstring _matrixServerUrl;
		std::string _msnLogin;
		std::string _matrixToken;

	public :
		ClientInfo();
		ClientInfo(const ClientInfo& obj);
		~ClientInfo();

		int getMSNDialectVersion() { return _msnDialectVersion; };
		void setMSNDialectVersion(int dialectVersion) { _msnDialectVersion = dialectVersion; };

		void setMatrixServerUrl(std::wstring url){
			_matrixServerUrl = url;
		};

		std::wstring getMatrixServerUrl() {
			return _matrixServerUrl;
		};

		std::string getMatrixToken() {
			return _matrixToken;
		}

		void setMatrixToken(std::string matrixToken) {
			_matrixToken = matrixToken;
		}

		void setMSNLogin(std::string msnLogin){
			_msnLogin = msnLogin;
		}
		
		std::string getMSNLogin(){
			return _msnLogin;
		}
};

