#pragma once
#include <string>
#include "MSNMembershipEnums.h"
#include "pugixml.hpp"
#include "MSNSoapMessages.h"
#include "XMLStringWriter.h"

class MSNMember {
    private :
        std::string _uid;
        MSNMembershipListType _listType;
        MSNMembershipState _state;
        std::string _type = "Passport";

        /* Datetime */
        std::string _lastChanged;
        std::string _joinedDate;
        std::string _expirationDate;
        std::string _passportName;

        bool _isPassportNameHidden = false;
        int _passportId = 0;
        int _cid;
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
        }

        std::string getStateAsString() {
            switch(_state) {
                case MSNMembershipState::Accepted :
                    return "Accepted";
            }
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
            pugi::xml_document doc;
            doc.load_string(MSNPSoapMessages::AB_FIND_MEMBERSHIP_MEMBER.c_str());
            auto membershipId = getListTypeAsString() + "\\" + _uid;
            
            doc.child("Member").child("MembershipId").set_value(membershipId.c_str());
            doc.child("Member").child("Type").set_value(_type.c_str());
            doc.child("Member").child("State").set_value(getStateAsString().c_str());
            doc.child("Member").child("Deleted").set_value(std::to_string(_isDeleted).c_str());
            doc.child("Member").child("LastChanged").set_value(_lastChanged.c_str());
            doc.child("Member").child("JoinedDate").set_value(_joinedDate.c_str());
            doc.child("Member").child("ExpirationDate").set_value(_expirationDate.c_str());
            doc.child("Member").child("PassportName").set_value(_passportName.c_str());
            doc.child("Member").child("IsPassportNameHidden").set_value(std::to_string(_isPassportNameHidden).c_str());
            doc.child("Member").child("PassportId").set_value(std::to_string(_passportId).c_str());
            doc.child("Member").child("CID").set_value(std::to_string(_cid).c_str());
            doc.child("Member").child("LookedupByCID").set_value(std::to_string(_lookedupByCID).c_str());

            XMLStringWriter writer;
            auto test = writer.node_to_string(doc.root());
            return test;
        };
};