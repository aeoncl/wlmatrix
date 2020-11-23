#pragma once
#include <vector>
#include <memory>
#include "ClientInfo.h"
#include <string>
class ClientInfoRepository {
	private :
		std::vector<std::shared_ptr<ClientInfo>> _clients;
	public :
		ClientInfoRepository() {};
		ClientInfoRepository(const ClientInfoRepository& obj);
		~ClientInfoRepository();
		ClientInfo* findClientByLogin(std::string id);
		void addClient(std::shared_ptr<ClientInfo> client);
		void removeClient(std::shared_ptr<ClientInfo> client);
		int getClientCount();
		std::vector<std::shared_ptr<ClientInfo>> getClients();
};

