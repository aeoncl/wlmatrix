#include "MainController.h"
#include <thread>
#include "MSNNotificationServer.h"
#include "MSNSwitchboardServer.h"
#include "cpprest/http_listener.h"

using namespace web;
using namespace http;
using namespace experimental;
using namespace listener;

/* Constructor */
MainController::MainController() {
	ClientInfoRepository clientRepo = ClientInfoRepository();
	std::thread msnNotifThread([this, clientRepo] {createMSNNotifServer(clientRepo); });
	msnNotifThread.detach();
	std::thread msnSwitchboardThread([this, clientRepo] {createMSNSwitchboardServer(clientRepo); });
	msnSwitchboardThread.detach();
	
	std::thread msnSoapServer([this, clientRepo] {createMSNSoapServer(clientRepo); });
	msnSoapServer.detach();
}

/* Private */
void MainController::createMSNNotifServer(ClientInfoRepository repo) {
	//ran in another thread
	MSNNotificationServer msnNotificationServer(repo);
	msnNotificationServer.listen();
}

/* Private */
void MainController::createMSNSwitchboardServer(ClientInfoRepository repo) {
	//ran in another thread
	MSNSwitchboardServer msnSwitchboardServer(repo);
	msnSwitchboardServer.listen();
}

/* Private */
void MainController::createMSNSoapServer(ClientInfoRepository repo) {
	utility::string_t url_utf16 = utility::conversions::to_utf16string("http://localhost:8080");
	http::uri uri(url_utf16);
	http_listener soapServer(uri);
	soapServer.open().get();
}