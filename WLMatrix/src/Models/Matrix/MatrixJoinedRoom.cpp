#include "MatrixJoinedRoom.h"
#include "cpprest/json.h"
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

MatrixJoinedRoom MatrixJoinedRoom::deserializeJson(std::string json) {
    MatrixJoinedRoom room;
    json::value jsonAsObj = json::value::parse(json);
    auto timelineEvents = jsonAsObj.at(L"timeline").at(L"events").as_array();
    for(auto eventJson : timelineEvents) {
        MatrixEvent event;
        event.deserializeJson(utf16_to_utf8(eventJson.serialize()));
        room.addTimelineEvent(event);
    }

    auto stateEvents = jsonAsObj.at(L"state").at(L"events").as_array();
    for(auto eventJson : stateEvents) {
        MatrixEvent event;
        event.deserializeJson(utf16_to_utf8(eventJson.serialize()));
        room.addStateEvent(event);
    }
    return room;
}