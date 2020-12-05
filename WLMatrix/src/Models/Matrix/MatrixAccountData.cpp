#include "MatrixAccountData.h"
#include "cpprest/json.h"
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

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