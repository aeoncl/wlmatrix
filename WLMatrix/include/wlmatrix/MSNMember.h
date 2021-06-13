#pragma once
#include <string>
#include "MSNMembershipEnums.h"
#include "MSNSoapMessages.h"
#include "XMLStringWriter.h"
#include "tinyxml2.h"
#include "StringUtils.h"

class MSNMember {
    private :
        std::string _uid;
        MSNMembershipListType _listType;
        MSNMembershipState _state;
        std::string _type = "Passport";

        /* Datetime */
        std::string _lastChanged = "2020-11-14T14:18:52Z";
        std::string _joinedDate = "2020-11-14T14:18:52Z";
        std::string _expirationDate = "0001-01-01T00:00:00";
        std::string _passportName;

        bool _isPassportNameHidden = false;
        int _passportId = 0;
        std::string _cid = "";
        bool const _lookedupByCID = false;
        bool _isDeleted = false;

    public :
        void setUid(std::string uid) {
            _uid = uid;
        }

        void setListType(MSNMembershipListType listType) {
            _listType = listType;
        }

        void setState(MSNMembershipState state){
            _state = state;
        }

        void setLastChanged(std::string lastChanged){
            _lastChanged = lastChanged;
        }

        void setJoinedDate(std::string joinedDate){
            _joinedDate = joinedDate;
        }

        void setExpirationDate(std::string expirationDate){
            _expirationDate = expirationDate;
        }

        void setPassportName(std::string passportName){
            _passportName = passportName;
        }

        void setPassportId(int passportId){
            _passportId = passportId;
        }

        void setIsDeleted(bool isDeleted){
            _isDeleted = isDeleted;
        }

        void setCid(std::string cid){
            _cid = cid;
        }

        std::string getUid() {
            return _uid;
        }

        MSNMembershipListType getListType() {
             return _listType;
        }

        std::string getListTypeAsString(){
            switch(_listType){
                case MSNMembershipListType::Allow :
                    return "Allow";
                case MSNMembershipListType::Block :
                    return "Block";
                case MSNMembershipListType::Pending :
                    return "Pending";
                case MSNMembershipListType::Reverse :
                    return "Reverse";
            }
            return "";
        }

        std::string getStateAsString() {
            switch(_state) {
                case MSNMembershipState::Accepted :
                    return "Accepted";
            }
            return"";
        }

        MSNMembershipState getState(){
            return _state;
        }

        std::string getLastChanged(){
             return _lastChanged;
        }

        std::string getJoinedDate(){
             return _joinedDate;
        }

        std::string getExpirationDate(){
             return _expirationDate;
        }

        std::string getPassportName(){
            return _passportName;
        }

        int getPassportId(){
            return _passportId;
        }

        bool getIsDeleted(){
            return _isDeleted;
        }

        std::string serializeXML(){
            
            std::string memberXML = MSNPSoapMessages::AB_FIND_MEMBERSHIP_MEMBER;
            auto membershipId = getListTypeAsString() + "\\" + _uid;
            StringUtils::replaceAll(memberXML, "%membership_id%", membershipId);
            StringUtils::replaceAll(memberXML, "%type%", _type);
            StringUtils::replaceAll(memberXML, "%state%", getStateAsString());
            StringUtils::replaceAll(memberXML, "%deleted%", StringUtils::parseBoolean(_isDeleted));
            StringUtils::replaceAll(memberXML, "%last_changed%", _lastChanged);
            StringUtils::replaceAll(memberXML, "%join_date%", _joinedDate);
            StringUtils::replaceAll(memberXML, "%expiration_date%", _expirationDate);
            StringUtils::replaceAll(memberXML, "%passport_name%", _passportName);
            StringUtils::replaceAll(memberXML, "%is_passport_hidden%", StringUtils::parseBoolean(_isPassportNameHidden));
            StringUtils::replaceAll(memberXML, "%passport_id%", std::to_string(_passportId));
            StringUtils::replaceAll(memberXML, "%cid%", _cid);
            StringUtils::replaceAll(memberXML, "%looked_up_by_cid%", StringUtils::parseBoolean(_lookedupByCID));
            return memberXML;
        };
};