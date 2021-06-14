#pragma once
#include "MSNContact.h"


 void MSNContact::setContactId(std::string contactId){
            _contactId = contactId;
        };

        void MSNContact::setMSNContactType(MSNContactType contactType){
            _contactType = contactType;
        };

        void MSNContact::setPassportName(std::string passportName){
            _passportName = passportName;
        };

        void MSNContact::setDisplayName(std::string displayName){
            _displayName = displayName;
        };

        void MSNContact::setIsDeleted(bool isDeleted){
            _isDeleted = isDeleted;
        };

        void MSNContact::setLastChange(std::string lastChange){
            _lastChange = lastChange;
        };

        void MSNContact::setCid(std::string cid) {
            _cid = cid;
        }

        std::string MSNContact::getContactId(){
            return _contactId;
        }

        std::string MSNContact::getContactTypeAsString() {
            if(_contactType == MSNContactType::Me) {
                return "Me";
            } else {
                return "Regular";
            }
        }

std::string MSNContact::serializeXML() {
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
}