#include "MainController.h"
#include <thread>
#include "ClientInfoRepository.h"
#include "MSNNotificationServer.h"
#include "MSNSwitchboardServer.h"

/* Constructor */
MainController::MainController() {
	std::thread msnNotifThread([this] {createMSNNotifServer(); });
	msnNotifThread.detach();
	std::thread msnSwitchboardThread([this] {createMSNSwitchboardServer(); });
	msnSwitchboardThread.detach();
}

/* Private */
void MainController::createMSNNotifServer() {
	ClientInfoRepository clientRepo = ClientInfoRepository();
	//ran in another thread
	MSNNotificationServer msnNotificationServer(clientRepo);
	msnNotificationServer.listen();
}

/* Private */
void MainController::createMSNSwitchboardServer() {
	ClientInfoRepository clientRepo = ClientInfoRepository();
	//ran in another thread
	MSNSwitchboardServer msnSwitchboardServer(clientRepo);
	msnSwitchboardServer.listen();
}
