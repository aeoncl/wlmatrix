#pragma once
#include <string>
class ClientInfo {
	private :
		int _dialectVersion;
		std::string _login;
		std::string _password;

	public :
		int getDialectVersion() { return _dialectVersion; };
		void setDialectVersion(int dialectVersion) { _dialectVersion = dialectVersion; };
		std::string getLogin() { return _login; };
		std::string setLogin(std::string login) { _login = login; };
		std::string getPassword() { return _password; };
		std::string setPassword(std::string password) { _password = password; };

};

