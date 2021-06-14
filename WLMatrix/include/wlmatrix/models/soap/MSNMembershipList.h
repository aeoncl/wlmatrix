#pragma once
#include "MSNMembershipListType.h"
#include "MSNMember.h"
#include <string>
#include <vector>

class MSNMembershipList {

    private :
    MSNMembershipListType _type;
    std::vector<MSNMember> _list;

    public : 
        MSNMembershipList(MSNMembershipListType type) : _type(type){};
        MSNMembershipList(const MSNMembershipList& obj){
            _type = obj._type;
        };

        ~MSNMembershipList(){
            _list.clear();
        };

        void addMember(MSNMember member);
        std::string serializeXML();
};