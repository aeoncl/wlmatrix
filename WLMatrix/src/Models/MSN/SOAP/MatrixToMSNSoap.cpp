#include "MatrixToMSNSoap.h"
#include "MSNSoapMessages.h"
#include <iostream>
#include "XMLStringWriter.h"
#include <chrono>
#include <ctime>
#include "boost/date_time/gregorian/gregorian.hpp"

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
