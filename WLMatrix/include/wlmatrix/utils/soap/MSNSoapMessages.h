#pragma once
#include <string>
#include <vector>
class MSNPSoapMessages {

    public :
        static const std::vector<std::string> RST2_TOKEN;
        static const std::vector<std::string> RST2_RESPONSE_SUCCESS_TEMPLATE;
        static const std::vector<std::string> RST2_DOMAINS;

        static const std::string AB_FIND_CONTACTS_PAGED_RESPONSE;
        static const std::string AB_FIND_CONTACTS_PAGED_CONTACT;
        static const std::string AB_FIND_CONTACTS_PAGED_CONTACT_SELF;
        static const std::string AB_FIND_CONTACTS_PAGED_CIRCLE_REVERSE_INFO;

        static const std::string AB_FIND_CONTACTS_PAGED_DELTA_ERROR;
        static const std::string AB_FIND_MEMBERSHIP_RESPONSE;
        static const std::string AB_FIND_MEMBERSHIP_MEMBER;

        static const std::string AB_CONTACT_ME_ANNOTATIONS;

};