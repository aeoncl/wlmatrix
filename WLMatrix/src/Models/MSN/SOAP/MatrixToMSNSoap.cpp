#include "MatrixToMSNSoap.h"
#include "MSNSoapMessages.h"
#include <iostream>
#include "XMLStringWriter.h"
#include <chrono>
#include <ctime>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "MSNMember.h"
#include "CryptoUtils.h"
#include "MSNUtils.h"
#include <vector>


/* RST2 */
std::string MatrixToMSNSoap::getRST2Response(AuthResponse matrixResponse)
{
    pugi::xml_document rst2Template;
    boost::gregorian::date today(boost::gregorian::day_clock::local_day());
    boost::gregorian::date tomorrow = today + boost::gregorian::days(1);
    auto todayStr = boost::gregorian::to_iso_extended_string(today) + "T00:00:00Z";
    auto tomorrowStr = boost::gregorian::to_iso_extended_string(tomorrow) + "T00:00:00Z";
    std::vector<std::string> arguments{todayStr, tomorrowStr, "99F0F2954FE73088", todayStr, matrixResponse.getUserIdAsStr(), matrixResponse.getUserIdAsStr(), "Tom", "Bek", matrixResponse.getUserIdAsStr(), todayStr, tomorrowStr, ""};
    std::string out;
    for (int i = 0; i < MSNPSoapMessages::RST2_RESPONSE_SUCCESS_TEMPLATE.size() - 1; i++)
    {
        out.append(MSNPSoapMessages::RST2_RESPONSE_SUCCESS_TEMPLATE.at(i));
        out.append(arguments.at(i));
    }
    out.append(getAllTokens(matrixResponse.getAccessTokenAsStr(), todayStr, tomorrowStr));
    out.append(MSNPSoapMessages::RST2_RESPONSE_SUCCESS_TEMPLATE.back());

    return out;
};

std::string MatrixToMSNSoap::getAllTokens(std::string token, std::string today, std::string tomorrow)
{
    std::string out;
    for (int i = 0; i < MSNPSoapMessages::RST2_DOMAINS.size(); i++)
    {
        auto rstDomain = MSNPSoapMessages::RST2_DOMAINS.at(i);
        auto RSTToken = forgeRST2Token(rstDomain, token, today, tomorrow, i + 1);
        out.append(RSTToken);
    }
    return out;
}

std::string MatrixToMSNSoap::forgeRST2Token(std::string domain, std::string token, std::string today, std::string tomorrow, int number)
{
    std::vector<std::string> arguments{domain, today, tomorrow, std::to_string(number), token, std::to_string(number), "tgoPVK67sU36fQKlGLMgWgTXp7oiaQgE", ""};
    std::string out;
    for (int i = 0; i < MSNPSoapMessages::RST2_TOKEN.size(); i++)
    {
        out.append(MSNPSoapMessages::RST2_TOKEN[i]);
        out.append(arguments[i]);
    }
    return out;
}


/* ABServices */
std::string MatrixToMSNSoap::getFindMembershipResponse(SyncResponse matrixResponse) {
     pugi::xml_document xml;

        xml.load_string(MSNPSoapMessages::AB_FIND_MEMBERSHIP_RESPONSE.c_str());
        pugi::xpath_node memberships = xml.child("soap:Envelope").child("soap:Body").child("FindMembershipResponse").child("FindMembershipResult").child("Services").child("Service").child("Memberships");
        
        std::vector<MSNMember> allowList;
        std::vector<MSNMember> reverseList;
        std::vector<MSNMember> blockList;
        std::vector<MSNMember> pendingList;

        auto joinedRooms = matrixResponse.getJoinedRooms();
        for(auto joinedRoom : joinedRooms) {
            auto directBuddy = matrixResponse.getDirectBuddy(joinedRoom.getId());
            if(directBuddy != ""){
                //room is a dm.
                MSNMember member;
                member.setUid(CryptoUtils::getMD5uuid(joinedRoom.getId()));
                member.setState(MSNMembershipState::Accepted);
                member.setPassportName(MSNUtils::getMSNUriForMatrixUri(directBuddy));
                allowList.push_back(member);

                if(joinedRoom.containsInvitedMember()) {
                    //is in reverse too
                    reverseList.push_back(member);
                }

            }else{
                //room is a circle.
                //circles are automatically in reverse.
                //No circles in memberships.
            }
        }

        
        /*headerTimeStamp.node().child("wsu:Created").append_child(pugi::node_pcdata).set_value(todayStr.c_str());
        headerTimeStamp.node().child("wsu:Expires").append_child(pugi::node_pcdata).set_value(tomorrowStr.c_str());

        pugi::xpath_node headerPuid = rst2Template.child("S:Envelope").child("S:Header").child("psf:pp");
        headerPuid.node().child("psf:serverInfo").attribute("ServerTime").set_value(todayStr.c_str());
        headerPuid.node().child("psf:credProperties").find_child_by_attribute("Name", "CID").append_child(pugi::node_pcdata).set_value(matrixResponse.getUserIdAsStr().c_str());
        headerPuid.node().child("psf:credProperties").find_child_by_attribute("Name", "AuthMembername").append_child(pugi::node_pcdata).set_value(matrixResponse.getUserIdAsStr().c_str());
        
        pugi::xpath_node bodyTokenSpace = rst2Template.child("S:Envelope").child("S:Body").child("wst:RequestSecurityTokenResponseCollection");
        pugi::xml_node token1 = forgeRST2Token("messengerclear.live.com", matrixResponse.getAccessTokenAsStr(), todayStr, tomorrowStr, 1);
        bodyTokenSpace.node().insert_child_after(pugi::node_element, token1);
        
        XMLStringWriter writer;
        auto test = writer.node_to_string(rst2Template);

        std::cout << "TEST: " << test << std::endl;*/

        return "";

};