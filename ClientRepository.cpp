#include "ClientRepository.h"

/* Copystructor */
ClientRepository::ClientRepository(const ClientRepository& obj) {
    this->_clients = obj._clients;
}

/* Destructor */
ClientRepository::~ClientRepository() {
    this->_clients.clear();
}

MSNClient* ClientRepository::findClientById(std::string id) {
    for (auto client : this->_clients) {
        auto current = client.get();
        if (current->getId() == id) {
            return current;
        }
    }
    return nullptr;
}

void ClientRepository::addClient(std::shared_ptr<MSNClient> client) {
    this->_clients.push_back(client);
}

void ClientRepository::removeClient(std::shared_ptr<MSNClient> client) {
    auto findResult = std::find(_clients.begin(), _clients.end(), client);
    if (findResult != _clients.end()) {
        //found
        _clients.erase(findResult);
    }
}

int ClientRepository::getClientCount()
{
    return this->_clients.size();
}

std::vector<std::shared_ptr<MSNClient>> ClientRepository::getClients() {
    return this->_clients;
}


