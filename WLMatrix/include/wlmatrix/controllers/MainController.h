#pragma once
#include "ClientInfoRepository.h"
#include "MSNSoapServer.h"

class MainController {
	public :
		MainController();
	private :
		MSNSoapServer* _soapServer;
		ClientInfoRepository* _repo;
		void createMSNNotifServer(ClientInfoRepository* repo);
		void createMSNSwitchboardServer(ClientInfoRepository* repo);
};