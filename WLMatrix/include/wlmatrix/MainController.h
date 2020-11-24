#pragma once
#include "ClientInfoRepository.h"
class MainController {
	public :
		MainController();
	private :
		void createMSNNotifServer(ClientInfoRepository repo);
		void createMSNSwitchboardServer(ClientInfoRepository repo);
		void createMSNSoapServer(ClientInfoRepository repo);

};