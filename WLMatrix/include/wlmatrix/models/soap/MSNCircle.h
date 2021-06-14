#pragma once
#include <string>

class MSNCircle {
    private :
        int const _domain = 1;
        int const _type = 2;
        int const _membershipAccess = 0;
        bool const _isPresenceEnabled = true;
        int const _requestMembershipOption = 0;

        std::string _hostedDomain;
        std::string _profileLastUpdated;
        std::string _createDate;
        std::string _lastUpdated;

        std::string _role;
        std::string _state;

        std::string _name;
        bool const _isNotMobileVisible = false;
        bool _isFavorite = false;
        bool _isFamily = false;
        bool _isDeleted = false;
    
    public :

        void setHostedDomain(std::string hostedDomain);

        void setProfileLastUpdated(std::string profileLastUpdated);

        void setCreateDate(std::string createDate);

        void setLastUpdated(std::string lastUpdated);

        void setRole(std::string role);
        void setProfileLastUpdate(std::string name);
        void setIsFavorite(bool isFavorite);

        void setIsFamily(bool isFamily);

        void setIsDeleted(bool isDeleted);

};