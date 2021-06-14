#include "MatrixEvent.h"
#include "cpprest/json.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <any>
using namespace web;
using namespace json;
using namespace utility;
using namespace conversions;

void MatrixEvent::deserializeJson(std::string json)
{
    json::value jsonAsObj = json::value::parse(json);
    auto currentType = jsonAsObj.at(L"type").as_string();
    this->_type = utf16_to_utf8(currentType);

    auto content = jsonAsObj.at(L"content").as_object();
    for (auto entry : content)
    {
        if (entry.second.is_string())
        {
            setProperty<std::string>(utf16_to_utf8(entry.first), utf16_to_utf8(entry.second.as_string()));
        }
        else if (entry.second.is_integer())
        {
            setProperty<int>(utf16_to_utf8(entry.first), entry.second.as_integer());
        }
        else if (entry.second.is_array())
        {
            auto array = entry.second.as_array();
            std::vector<std::string> toAdd;
            for (auto elem : array)
            {
                if (elem.is_string())
                {
                    toAdd.push_back(utf16_to_utf8(elem.as_string()));
                }
            }
            setProperty<std::vector<std::string>>(utf16_to_utf8(entry.first), toAdd);
        }
    }
}
