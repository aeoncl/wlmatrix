#include "MatrixAccountData.h"
#include "cpprest/json.h"
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

std::vector<MatrixEvent> MatrixAccountData::getEvents() {
            return _events;
        };

        void MatrixAccountData::addEvent(MatrixEvent event){
            _events.push_back(event);
        };

        std::optional<MatrixEvent> MatrixAccountData::getEventByType(std::string type) {
            for(auto event : _events) {
                if(event.getType() == type){
                    return std::make_optional(event);
                }
            }
        return std::nullopt;
        };


MatrixAccountData MatrixAccountData::deserializeJson(std::string json) {
    json::value jsonAsObj = json::value::parse(json);
    MatrixAccountData accountData;
    auto events = jsonAsObj.at(L"events").as_array();
    for(auto eventJson : events) {
        MatrixEvent event;
        event.deserializeJson(utf16_to_utf8(eventJson.serialize()));
        accountData.addEvent(event);
    }
    return accountData;
};