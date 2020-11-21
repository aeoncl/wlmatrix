#include "MainController.h"
#include <thread>
#include "MSNServer.h"
/* Constructor */
MainController::MainController() {
	std::thread thread([this] {createMSNPServer(); });
	thread.detach();
}

/* Private */
void MainController::createMSNPServer() {
	//ran in another thread
	std::cout << "Creating MSNP Server thread.\n";
	MSNServer serv(1863);
	serv.listen();
}
