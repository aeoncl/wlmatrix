#include "MSNUtils.h"
#include <regex>

     std::string MSNUtils::getMatrixUriForMSNUri(std::string msnUri){
         return "";
     }

    std::string MSNUtils::getMSNUriForMatrixUri(std::string matrixUri){
        auto matchResults = std::smatch{};
	    bool const hasMatches = std::regex_search(matrixUri, matchResults, std::regex("@(.+):(.+)"));

        //Todo make this not suck
	    if (hasMatches) {
		    auto username = matchResults[1].str();
            auto domain = matchResults[2].str();

            return username + "@" + domain;
        }

        return "";
     }
