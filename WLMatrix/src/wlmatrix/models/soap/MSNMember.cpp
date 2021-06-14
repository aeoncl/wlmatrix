#pragma once
#include "MSNMember.h"

void MSNMember::setUid(std::string uid) {
            _uid = uid;
        }

        void MSNMember::setListType(MSNMembershipListType listType) {
            _listType = listType;
        }

        void MSNMember::setState(MSNMembershipState state){
            _state = state;
        }

        void MSNMember::setLastChanged(std::string lastChanged){
            _lastChanged = lastChanged;
        }

        void MSNMember::setJoinedDate(std::string joinedDate){
            _joinedDate = joinedDate;
        }

        void MSNMember::setExpirationDate(std::string expirationDate){
            _expirationDate = expirationDate;
        }

        void MSNMember::setPassportName(std::string passportName){
            _passportName = passportName;
        }

        void MSNMember::setPassportId(int passportId){
            _passportId = passportId;
        }

        void MSNMember::setIsDeleted(bool isDeleted){
            _isDeleted = isDeleted;
        }

        void MSNMember::setCid(std::string cid){
            _cid = cid;
        }

        std::string MSNMember::getUid() {
            return _uid;
        }

        MSNMembershipListType MSNMember::getListType() {
             return _listType;
        }

        std::string MSNMember::getListTypeAsString(){
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

        std::string MSNMember::getStateAsString() {
            switch(_state) {
                case MSNMembershipState::Accepted :
                    return "Accepted";
            }
            return"";
        }

        MSNMembershipState MSNMember::getState(){
            return _state;
        }

        std::string MSNMember::getLastChanged(){
             return _lastChanged;
        }

        std::string MSNMember::getJoinedDate(){
             return _joinedDate;
        }

        std::string MSNMember::getExpirationDate(){
             return _expirationDate;
        }

        std::string MSNMember::getPassportName(){
            return _passportName;
        }

        int MSNMember::getPassportId(){
            return _passportId;
        }

        bool MSNMember::getIsDeleted(){
            return _isDeleted;
        }

        std::string MSNMember::serializeXML(){
            
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