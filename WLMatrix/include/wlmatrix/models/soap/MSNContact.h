#pragma once
#include <string>
#include "MSNContactType.h"
#include "MSNSoapMessages.h"
#include "StringUtils.h"
class MSNContact {
    private :
        std::string _contactId;
        MSNContactType _contactType;
        std::string _passportName;
        std::string _displayName;
        bool _isDeleted = false;
        std::string _lastChange = "2020-11-14T14:18:52Z";

        int const _puid = 0;
        std::string _cid = "";
        bool const _isPassportNameHidden = false;
        bool const _IsNotMobileVisible = false;
        bool const _isMobileIMEnabled = false;
        bool const _isMessengerUser = true;
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
        std::string serializeXML();

        void setContactId(std::string contactId);
        void setMSNContactType(MSNContactType contactType);
        void setPassportName(std::string passportName);

        void setDisplayName(std::string displayName);

        void setIsDeleted(bool isDeleted);
        void setLastChange(std::string lastChange);
        void setCid(std::string cid);
        std::string getContactId();

        std::string getContactTypeAsString();
};