#include "SyncResponse.h"
#include "cpprest/json.h"
#include "MatrixAccountData.h"
#include <unordered_map>
#include <any>

using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

SyncResponse SyncResponse::deserializeJson(std::string json) {
        json::value jsonAsObj = json::value::parse(json);
        SyncResponse response;
        response.setAccountData(MatrixAccountData::deserializeJson(utf16_to_utf8(jsonAsObj.at(L"account_data").serialize())));
        auto joinedRooms = jsonAsObj.at(L"rooms").at(L"join").as_object();
        for(auto room : joinedRooms) {
                auto roomToAdd = MatrixJoinedRoom::deserializeJson(utf16_to_utf8(room.second.serialize()));
                roomToAdd.setId(utf16_to_utf8(room.first));
                response.addJoinedRoom(roomToAdd);
        }
        return response;
}

std::unordered_map<std::string, std::any> SyncResponse::getDirectList() {
        auto test = this->_accountData.getEventByType("m.direct");
        return test.getContent();
}

bool SyncResponse::isRoomDirect(std::string roomId){
        auto directs = getDirectList();
        for(auto direct : directs){
        auto roomArrayForMember = std::any_cast<std::vector<std::string>>(direct.second);
                for(auto currentRoomId : roomArrayForMember){
                        if(currentRoomId == roomId){
                                return true;
                        }
                }
        }
        return false;
}



