#include "MSNPHandshake.h"
std::string MSNPHandshake::interpretMessage(std::string message) {
	std::string response = "";

	auto const regex = std::regex("(MSNP[\d]+)");
	auto matchResults = std::smatch{};
	bool const hasMatches = std::regex_search(message, matchResults, regex);

	if (hasMatches) {
		auto maxMSNPVer = message.substr(4,2);
		//int maxMSNPVerParsed = std::stoi(maxMSNPVer);
		response = "VER 1 MSNP" + maxMSNPVer + "\n";
	}
	return response;
}
