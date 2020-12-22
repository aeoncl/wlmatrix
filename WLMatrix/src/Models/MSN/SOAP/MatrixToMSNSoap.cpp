#include "MatrixToMSNSoap.h"
#include "MSNSoapMessages.h"
#include "MSNMembershipList.h"
#include <iostream>
#include "XMLStringWriter.h"
#include <chrono>
#include <ctime>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "MSNMember.h"
#include "CryptoUtils.h"
#include "MSNUtils.h"
#include <vector>
#include "tinyxml2.h"

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
std::string MatrixToMSNSoap::getFindMembershipResponse(SyncResponse matrixResponse, std::string msnLogin) {
    std::string findMembershipXML = MSNPSoapMessages::AB_FIND_MEMBERSHIP_RESPONSE;

    MSNMembershipList allowList(MSNMembershipListType::Allow);
    MSNMembershipList reverseList(MSNMembershipListType::Reverse);
    MSNMembershipList blockList(MSNMembershipListType::Block);
    MSNMembershipList pendingList(MSNMembershipListType::Pending);

        auto joinedRooms = matrixResponse.getJoinedRooms();
        for(auto joinedRoom : joinedRooms) {
            auto directBuddy = matrixResponse.getDirectBuddy(joinedRoom.getId());
            MSNMember member;

            if(directBuddy != ""){
                //room is a dm.
                member.setUid(CryptoUtils::getMD5uuid(joinedRoom.getId()));
                member.setState(MSNMembershipState::Accepted);
                member.setPassportName(MSNUtils::getMSNUriForMatrixUri(directBuddy));
                member.setJoinedDate("0001-01-01T00:00:00");
                member.setLastChanged("0001-01-01T00:00:00");
                member.setExpirationDate("0001-01-01T00:00:00");
                allowList.addMember(member);
                if(joinedRoom.containsInvitedMember()) {
                    //is in reverse too.
                    reverseList.addMember(member);
                }

            }else{
                //room is a circle.
                //circles are automatically in reverse.
                //No circles in memberships.
            }

        }
        StringUtils::replaceAll(findMembershipXML, "%creator_passport_name%", msnLogin);
        StringUtils::replaceAll(findMembershipXML, "%membership_last_change%", "0001-01-01T00:00:00");
        StringUtils::replaceAll(findMembershipXML, "%allowlist%", allowList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%reverselist%", reverseList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%blocklist%", blockList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%pendinglist%", pendingList.serializeXML());


        std::cout << "PRINT TEST FIND MEMBERSHIP : " << findMembershipXML << std::endl;

        return findMembershipXML;

};