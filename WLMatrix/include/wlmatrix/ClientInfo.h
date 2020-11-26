#pragma once
#include <string>
class ClientInfo {
	private :
		int _dialectVersion;
		std::string _login;
		std::string _password;
		std::string _matrixToken;

	public :
		int getDialectVersion() { return _dialectVersion; };
		void setDialectVersion(int dialectVersion) { _dialectVersion = dialectVersion; };
		std::string getLogin() { return _login; };
		void setLogin(std::string login) { _login = login; };
		std::string getPassword() { return _password; };
		void setPassword(std::string password) { _password = password; };
		std::string getMatrixToken() { return _matrixToken; };
		void setMatrixToken(std::string matrixToken) { _matrixToken = matrixToken; };


};

