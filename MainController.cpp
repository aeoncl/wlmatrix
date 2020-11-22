#include "MainController.h"
#include <thread>
#include "MSNServer.h"
#include "ClientRepository.h"
/* Constructor */
MainController::MainController() {
	std::thread thread([this] {createMSNPServer(); });
	thread.detach();
}

/* Private */
void MainController::createMSNPServer() {
	ClientRepository clientRepo = ClientRepository();
	//ran in another thread
	std::cout << "Creating MSNP Server thread." << std::endl;
	MSNServer serv(1863, clientRepo);
	serv.listen();
}
