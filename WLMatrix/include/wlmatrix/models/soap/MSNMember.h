#pragma once
#include <string>
#include "MSNMembershipListType.h"
#include "MSNMembershipState.h"
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
        void setUid(std::string uid);

        void setListType(MSNMembershipListType listType);
        void setState(MSNMembershipState state);

        void setLastChanged(std::string lastChanged);
        void setJoinedDate(std::string joinedDate);
        void setExpirationDate(std::string expirationDate);
        void setPassportName(std::string passportName);
        void setPassportId(int passportId);
        void setIsDeleted(bool isDeleted);
        void setCid(std::string cid);
        std::string getUid();

        MSNMembershipListType getListType();
        std::string getListTypeAsString();
        std::string getStateAsString();

        MSNMembershipState getState();

        std::string getLastChanged();
        std::string getJoinedDate();
        std::string getExpirationDate();
        std::string getPassportName();

        int getPassportId();

        bool getIsDeleted();

        std::string serializeXML();
};