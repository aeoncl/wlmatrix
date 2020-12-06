#pragma once
#include <string>
#include "MSNContactType.h"
class MSNContact {
    private :
        std::string _contactId;
        MSNContactType _contactType;
        std::string _passportName;
        std::string _displayName;
        bool _isDeleted = false;
        std::string _lastChange = "0001-01-01T00:00:00";

        int const _puid = 0;
        int const _cid = 0;
        bool const _isPassportNameHidden = false;
        bool const _IsNotMobileVisible = false;
        bool const _isMobileIMEnabled = false;
        bool const _isMobileIMEnabled = true;
        bool const _isFavorite = false;
        bool const _isSmtp = false;
        bool const _hasSpace = false;
        std::string const _spotWatchState = "NoDevice";
        std::string const _birthdate = "0001-01-01T00:00:00";
        std::string const _primaryEmailType = "ContactEmailPersonal";
        std::string const _primaryLocation = "ContactLocationPersonal";
        std::string const _primaryPhone = "ContactPhonePersonal";
        std::string const _gender = "Unspecified";
        std::string const _timeZone = "None";
        bool const _isPrivate = false;
    
    public :
        void setContactId(std::string contactId){
            _contactId = contactId;
        };

        void setMSNContactType(MSNContactType contactType){
            _contactType = contactType;
        };

        void setPassportName(std::string passportName){
            _passportName = passportName;
        };

        void setDisplayName(std::string displayName){
            _displayName = displayName;
        };

        void setIsDeleted(bool isDeleted){
            _isDeleted = isDeleted;
        };

        void setLastChange(std::string lastChange){
            _lastChange = lastChange;
        };
};