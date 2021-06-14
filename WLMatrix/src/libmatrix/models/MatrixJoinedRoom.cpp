#include "MatrixJoinedRoom.h"
#include "cpprest/json.h"
#include <string>
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

MatrixJoinedRoom::MatrixJoinedRoom(std::string id) : _id(id){};
MatrixJoinedRoom::MatrixJoinedRoom(){};

std::string MatrixJoinedRoom::getId()
{
    return _id;
};

void MatrixJoinedRoom::setId(std::string id)
{
    _id = id;
};

void MatrixJoinedRoom::addStateEvent(MatrixEvent event)
{
    _state.push_back(event);
}

void MatrixJoinedRoom::addTimelineEvent(MatrixEvent event)
{
    _timeline.push_back(event);
}

std::vector<MatrixEvent> MatrixJoinedRoom::getStateEventsForType(std::string type)
{
    std::vector<MatrixEvent> out;
    for (auto event : _state)
    {
        if (event.getType() == type)
        {
            out.push_back(event);
        }
    }
    return out;
}

bool MatrixJoinedRoom::containsInvitedMember()
{
    for (auto stateEvent : _state)
    {
        if (stateEvent.getType() == "m.room.member" && stateEvent.getProperty<std::string>("membership") == "join")
        {
            return true;
        }
    }
    return false;
}

MatrixJoinedRoom MatrixJoinedRoom::deserializeJson(std::string json)
{
    MatrixJoinedRoom room;
    json::value jsonAsObj = json::value::parse(json);
    auto timelineEvents = jsonAsObj.at(L"timeline").at(L"events").as_array();
    for (auto eventJson : timelineEvents)
    {
        MatrixEvent event;
        event.deserializeJson(utf16_to_utf8(eventJson.serialize()));
        room.addTimelineEvent(event);
    }

    auto stateEvents = jsonAsObj.at(L"state").at(L"events").as_array();
    for (auto eventJson : stateEvents)
    {
        MatrixEvent event;
        event.deserializeJson(utf16_to_utf8(eventJson.serialize()));
        room.addStateEvent(event);
    }
    return room;
}