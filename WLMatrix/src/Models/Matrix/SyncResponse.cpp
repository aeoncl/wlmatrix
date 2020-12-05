#include "SyncResponse.h"
#include "cpprest/json.h"
#include "MatrixAccountData.h"
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
