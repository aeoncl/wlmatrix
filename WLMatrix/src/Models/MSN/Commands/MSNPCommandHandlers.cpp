#include "IMSNPCommandHandler.h"
#include "MSNClient.h"
#include "StringUtils.h"
#include "MSNPCommandHandlers.h"

std::vector<std::string> MSNPVER::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses;
	auto matchResults = std::smatch{};
	bool const hasMatches = std::regex_search(message, matchResults, std::regex("(MSNP[\\d]+)"));

	if (hasMatches) {
		auto firstMatch = matchResults[0].str();
		auto maxMSNPVer = firstMatch.substr(4, 2);
		int maxMSNPVerParsed = std::stoi(maxMSNPVer);
		client->setDialectVersion(maxMSNPVerParsed);
		//client.setDialectVersion(maxMSNPVerParsed); TODO set client version
		auto response = "VER 1 MSNP" + maxMSNPVer + "\r\n";
		responses.push_back(response);
	}
	return responses;
}

/*
>>> CVR 2 0x0409 winnt 6.0.0 i386 MSNMSGR 14.0.8117.0416 msmsgs aeon@test.com
<<< CVR 2 14.0.8117.0416 14.0.8117.0416 14.0.8117.0416 localhost localhost
*/
std::vector<std::string> MSNPCVR::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses;
	auto matches = StringUtils::splitWords(message);
	auto version = matches[7];
	auto clientMail = matches[9];
	auto commandOrder = matches[1];
	client->setLogin(clientMail);
	auto response = "CVR " + commandOrder + " " + version + " " + version + " " + version + " localhost localhost\r\n";
	responses.push_back(response);
	return responses;
}

/*
I phase : 
	>>> USR 3 SSO I aeon@test.com
	<<< USR 3 SSO S MBI_KEY_OLD LAhAAUzdC+JvuB33nooLSa6Oh0oDFCbKrN57EVTY0Dmca8Reb3C1S1czlP12N8VU
S phase :
	>>> USR 4 SSO S t=ssotoken {55192CF5-588E-4ABE-9CDF-395B616ED85B}
	<<< USR 4 OK aeon@test.com 1 0
*/
std::vector<std::string> MSNPUSR::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	//SSO login
	std::vector<std::string> responses;

	auto matches = StringUtils::splitWords(message);
	auto phase = matches[3];
	auto commandOrder = matches[1];
	if (phase == "I") {
		auto response = "USR " + commandOrder + " SSO S MBI_KEY_OLD LAhAAUzdC+JvuB33nooLSa6Oh0oDFCbKrN57EVTY0Dmca8Reb3C1S1czlP12N8VU\r\n";
		responses.push_back(response);
		//responses.push_back("GCF 0 1187\r\n<Policies><Policy type=\"SHIELDS\" checksum=\"D9705A71BA841CB38955822E048970C3\"><config> <shield><cli maj=\"7\" min=\"0\" minbld=\"0\" maxbld=\"9999\" deny=\" \" /></shield> <block></block></config></Policy><Policy type=\"ABCH\" checksum=\"03DC55910A9CB79133F1576221A80346\"><policy><set id=\"push\" service=\"ABCH\" priority=\"200\">      <r id=\"pushstorage\" threshold=\"180000\" />    </set><set id=\"delaysup\" service=\"ABCH\" priority=\"150\">  <r id=\"whatsnew\" threshold=\"1800000\" />  <r id=\"whatsnew_storage_ABCH_delay\" timer=\"1800000\" />  <r id=\"whatsnewt_link\" threshold=\"900000\" trigger=\"QueryActivities\" /></set>  <c id=\"PROFILE_Rampup\">100</c></policy></Policy><Policy type=\"ERRORRESPONSETABLE\" checksum=\"6127EEDCE860F45C1692896F5248AF6F\"><Policy> <Feature type=\"3\" name=\"P2P\">  <Entry hr=\"0x81000398\" action=\"3\"/>  <Entry hr=\"0x82000020\" action=\"3\"/> </Feature> <Feature type=\"4\">  <Entry hr=\"0x81000440\" /> </Feature> <Feature type=\"6\" name=\"TURN\">  <Entry hr=\"0x8007274C\" action=\"3\" />  <Entry hr=\"0x82000020\" action=\"3\" />  <Entry hr=\"0x8007274A\" action=\"3\" /> </Feature></Policy></Policy><Policy type=\"P2P\" checksum=\"815D4F1FF8E39A85F1F97C4B16C45177\"><ObjStr SndDly=\"1\" /></Policy></Policies>\r\n");
	}
	else {
		auto email = client->getLogin();
		auto response = "USR " + commandOrder + " OK " + email + " 1 0\r\n";

		responses.push_back(response);
		responses.push_back("SBS 0 null\r\n");
		responses.push_back("MSG Hotmail Hotmail 0\r\n");
		responses.push_back("UBX 1:" + email + " 0\r\n");
	}
	return responses;
}

std::vector<std::string> MSNPUUX::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses;
	auto matches = StringUtils::splitWords(message);
	auto commandOrder = matches[1];

	responses.push_back("UUX " + commandOrder + " 0\r\n");
	return responses;
}

std::vector<std::string> MSNPBLP::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses;
	auto matches = StringUtils::splitWords(message);
	auto commandOrder = matches[1];

	responses.push_back("BLP " + commandOrder + " 0\r\n");
	return responses;
}


std::vector<std::string> MSNPNG::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses{ "QNG 60\r\n" };
	return responses;
}

std::vector<std::string> MSNCHG::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses{ message+"\r\n" };
	return responses;
}

std::vector<std::string> MSNPEmpty::executeCommand(std::string message, std::shared_ptr<ClientInfo> client, int dialectVersion) const {
	std::vector<std::string> responses{ "UUX 0 0\r\n" };
	return responses;
}
