#pragma once
#include <vector>
#include <memory>
#include "MSNClient.h"
#include <string>
class ClientRepository {
	private :
		std::vector<std::shared_ptr<MSNClient>> _clients;
	public :
		ClientRepository() {};
		ClientRepository(const ClientRepository& obj);
		~ClientRepository();
		MSNClient* findClientById(std::string id);
		void addClient(std::shared_ptr<MSNClient> client);
		void removeClient(std::shared_ptr<MSNClient> client);
		int getClientCount();
		std::vector<std::shared_ptr<MSNClient>> getClients();
};

