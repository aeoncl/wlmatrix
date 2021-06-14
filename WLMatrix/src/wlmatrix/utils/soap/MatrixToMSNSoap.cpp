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
#include "MSNContact.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/ptime.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"



/* RST2 */
std::string MatrixToMSNSoap::getRST2Response(AuthResponse matrixResponse, std::string msnLogin)
{
    pugi::xml_document rst2Template;
    boost::gregorian::date today(boost::gregorian::day_clock::local_day());
    boost::gregorian::date tomorrow = today + boost::gregorian::days(1);

    auto todayStr = boost::gregorian::to_iso_extended_string(today) + "T00:00:00Z";
    auto tomorrowStr = boost::gregorian::to_iso_extended_string(tomorrow) + "T00:00:00Z";
    std::string cid = CryptoUtils::getUuidAsDecimal(CryptoUtils::getMD5uuid(matrixResponse.getUserIdAsStr()));
    std::vector<std::string> arguments{todayStr, tomorrowStr, "99F0F2954FE73088", todayStr, cid, msnLogin, "John", "Doe", cid, todayStr, tomorrowStr, ""};
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
                member.setCid(CryptoUtils::getUuidAsDecimal(member.getUid()));
                member.setState(MSNMembershipState::Accepted);
                member.setPassportName(MSNUtils::getMSNUriForMatrixUri(directBuddy));
                member.setJoinedDate("2020-11-14T14:18:52Z");
                member.setLastChanged("2021-06-12T22:01:32Z");
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


            boost::gregorian::date today(boost::gregorian::day_clock::local_day());
    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
        int hours = timeLocal.time_of_day().hours();
        int minutes = timeLocal.time_of_day().minutes();
        int seconds = timeLocal.time_of_day().seconds();
        auto todayStr = boost::gregorian::to_iso_extended_string(today) + "T" + std::to_string(hours) + ":" + std::to_string(minutes) +":" + std::to_string(seconds) +"Z";



        StringUtils::replaceAll(findMembershipXML, "%session_id%", CryptoUtils::getRandomUuid());

        StringUtils::replaceAll(findMembershipXML, "%creator_passport_name%", msnLogin);
        StringUtils::replaceAll(findMembershipXML, "%membership_last_change%", todayStr);
                        StringUtils::replaceAll(findMembershipXML, "%last_change%", todayStr);
                StringUtils::replaceAll(findMembershipXML, "%create_date%", "2021-06-12T19:15:52Z");

        StringUtils::replaceAll(findMembershipXML, "%allowlist%", allowList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%reverselist%", reverseList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%blocklist%", blockList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%pendinglist%", pendingList.serializeXML());
        StringUtils::replaceAll(findMembershipXML, "%creator_cid%", CryptoUtils::getUuidAsDecimal(CryptoUtils::getMD5uuid(msnLogin)));



        std::cout << "PRINT TEST FIND MEMBERSHIP : " << findMembershipXML << std::endl;

        return findMembershipXML;

};


std::string MatrixToMSNSoap::getContactsPagedResponse(std::string msnLogin) {
    std::string contactsPagedResponse = MSNPSoapMessages::AB_FIND_CONTACTS_PAGED_RESPONSE;
    MSNContact me;
    me.setPassportName(msnLogin);
    me.setContactId(CryptoUtils::getMD5uuid(msnLogin));
    me.setMSNContactType(MSNContactType::Me);
    me.setCid(CryptoUtils::getUuidAsDecimal(me.getContactId()));
    me.setDisplayName(msnLogin);
    
    StringUtils::replaceAll(contactsPagedResponse, "%contacts%", me.serializeXML());
    StringUtils::replaceAll(contactsPagedResponse, "%circles%", "");
        StringUtils::replaceAll(contactsPagedResponse, "%owner_cid%", CryptoUtils::getUuidAsDecimal(me.getContactId()));
        StringUtils::replaceAll(contactsPagedResponse, "%owner_email%", msnLogin);
        StringUtils::replaceAll(contactsPagedResponse, "%default%", "true");
        StringUtils::replaceAll(contactsPagedResponse, "%joined_namespace%", "false");
        StringUtils::replaceAll(contactsPagedResponse, "%bot%", "false");
        StringUtils::replaceAll(contactsPagedResponse, "%parent_managed%", "false");
        StringUtils::replaceAll(contactsPagedResponse, "%account_tier_last_changed%", "0001-01-01T00:00:00");
        StringUtils::replaceAll(contactsPagedResponse, "%profile_version%", "0");
        StringUtils::replaceAll(contactsPagedResponse, "%subscribe_external_partner%", "false");
        StringUtils::replaceAll(contactsPagedResponse, "%notify_external_partner%", "false");
        StringUtils::replaceAll(contactsPagedResponse, "%address_book_type%", "Individual");
        StringUtils::replaceAll(contactsPagedResponse, "%last_change%", "2020-11-14T14:18:52Z");
        StringUtils::replaceAll(contactsPagedResponse, "%dynamic_item_last_change%", "0001-01-01T00:00:00");
        StringUtils::replaceAll(contactsPagedResponse, "%creation_date%", "2020-11-14T14:18:52Z");

    return contactsPagedResponse;
}