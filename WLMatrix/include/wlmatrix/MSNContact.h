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
        std::string serializeXML() {
             std::string msnContactTemplate = MSNPSoapMessages::AB_FIND_CONTACTS_PAGED_CONTACT;
            if(_contactType == MSNContactType::Me) {
                msnContactTemplate = MSNPSoapMessages::AB_FIND_CONTACTS_PAGED_CONTACT_SELF;
            }
            StringUtils::replaceAll(msnContactTemplate, "%contact_id%", _contactId);
            StringUtils::replaceAll(msnContactTemplate, "%contact_type%", getContactTypeAsString());
            StringUtils::replaceAll(msnContactTemplate, "%quick_name%", _passportName);
            StringUtils::replaceAll(msnContactTemplate, "%passport_name%", _passportName);
            StringUtils::replaceAll(msnContactTemplate, "%passport_name_hidden%", "false");
            StringUtils::replaceAll(msnContactTemplate, "%display_name%", _displayName);
            StringUtils::replaceAll(msnContactTemplate, "%puid%", std::to_string(_puid));
            StringUtils::replaceAll(msnContactTemplate, "%cid%", _cid);
            StringUtils::replaceAll(msnContactTemplate, "%not_mobile_visible%", StringUtils::parseBoolean(_IsNotMobileVisible));
            StringUtils::replaceAll(msnContactTemplate, "%mobile_im_enabled%", StringUtils::parseBoolean(_isMobileIMEnabled));
            StringUtils::replaceAll(msnContactTemplate, "%messenger_user%", StringUtils::parseBoolean(_isMessengerUser));
            StringUtils::replaceAll(msnContactTemplate, "%favorite%", StringUtils::parseBoolean(_isFavorite));
            StringUtils::replaceAll(msnContactTemplate, "%smtp%", StringUtils::parseBoolean(_isSmtp));
            StringUtils::replaceAll(msnContactTemplate, "%hasSpace%", StringUtils::parseBoolean(_hasSpace));
            StringUtils::replaceAll(msnContactTemplate, "%spotwatch_state%", _spotWatchState);
            StringUtils::replaceAll(msnContactTemplate, "%birthday%", _birthdate);
            StringUtils::replaceAll(msnContactTemplate, "%primary_email_type%", _primaryEmailType);
            StringUtils::replaceAll(msnContactTemplate, "%primary_location%", _primaryLocation);
            StringUtils::replaceAll(msnContactTemplate, "%primary_phone%", _primaryPhone);
            StringUtils::replaceAll(msnContactTemplate, "%private%", StringUtils::parseBoolean(_isPrivate));
            StringUtils::replaceAll(msnContactTemplate, "%gender%", _gender);
            StringUtils::replaceAll(msnContactTemplate, "%timezone%", _timeZone);
            StringUtils::replaceAll(msnContactTemplate, "%deleted%", StringUtils::parseBoolean(_isDeleted));
            StringUtils::replaceAll(msnContactTemplate, "%last_change%", _lastChange);
            return msnContactTemplate;
        };

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

        void setCid(std::string cid) {
            _cid = cid;
        }

        std::string getContactId(){
            return _contactId;
        }

        std::string getContactTypeAsString() {
            if(_contactType == MSNContactType::Me) {
                return "Me";
            } else {
                return "Regular";
            }
        }


};