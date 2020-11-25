#include "ClientInfoRepository.h"
#include <iostream>

/* Copystructor */
ClientInfoRepository::ClientInfoRepository(const ClientInfoRepository& obj) {
    this->_clients = obj._clients;
}

/* Vaati */
ClientInfoRepository::~ClientInfoRepository() {
    this->_clients.clear();
    std::cout << "Client Repository destroyed" << std::endl;
}

ClientInfo* ClientInfoRepository::findClientByLogin(std::string login) {
    for (auto client : this->_clients) {
        auto current = client.get();
        if (current->getLogin() == login) {
            return current;
        }
    }
    return nullptr;
}

void ClientInfoRepository::addClient(std::shared_ptr<ClientInfo> client) {
    this->_clients.push_back(client);
}

void ClientInfoRepository::removeClient(std::shared_ptr<ClientInfo> client) {
    auto findResult = std::find(_clients.begin(), _clients.end(), client);
    if (findResult != _clients.end()) {
        //found
        _clients.erase(findResult);
    }
}

int ClientInfoRepository::getClientCount()
{
    return this->_clients.size();
}

std::vector<std::shared_ptr<ClientInfo>> ClientInfoRepository::getClients() {
    return this->_clients;
}


