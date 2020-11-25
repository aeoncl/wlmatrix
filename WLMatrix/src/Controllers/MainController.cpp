#include "MainController.h"
#include <thread>
#include "MSNNotificationServer.h"
#include "MSNSwitchboardServer.h"

/* Constructor */
MainController::MainController() {
	_repo = new ClientInfoRepository();
	std::thread msnNotifThread([this] {createMSNNotifServer(this->_repo); });
	msnNotifThread.detach();
	std::thread msnSwitchboardThread([this] {createMSNSwitchboardServer(this->_repo); });
	msnSwitchboardThread.detach();
	
	_soapServer = new MSNSoapServer(*_repo);
	_soapServer->listen();
}

/* Private */
void MainController::createMSNNotifServer(ClientInfoRepository* repo) {
	//ran in another thread
	MSNNotificationServer msnNotificationServer(*repo);
	msnNotificationServer.listen();
}

/* Private */
void MainController::createMSNSwitchboardServer(ClientInfoRepository* repo) {
	//ran in another thread
	MSNSwitchboardServer msnSwitchboardServer(*repo);
	msnSwitchboardServer.listen();
}