#include "MSNPHandshake.h"
#include "MSNPInterpreterFactory.h"
#include "MSNClient.h"
#include <iostream>
MSNPHandshake::MSNPHandshake()
{
}
MSNPHandshake::~MSNPHandshake() {
	std::cout << "MSNPHandshake destroyed!" << std::endl;
}
std::string MSNPHandshake::interpretMessage(std::string message, MSNClient& client) const {
	std::string response = "";
	auto const regex = std::regex("(MSNP[\\d]+)");
	auto matchResults = std::smatch{};
	bool const hasMatches = std::regex_search(message, matchResults, regex);

	if (hasMatches) {
		auto firstMatch = matchResults[0].str();
		auto maxMSNPVer = firstMatch.substr(4,2);
		int maxMSNPVerParsed = std::stoi(maxMSNPVer);
		client.setInterpreter(MSNPInterpreterFactory::getInterpreter(maxMSNPVerParsed));
		response = "VER 1 MSNP" + maxMSNPVer + "\n";
	}
	return response;
}
