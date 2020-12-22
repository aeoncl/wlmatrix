#pragma once
#include "MSNMembershipEnums.h"
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

        void addMember(MSNMember member) {
            _list.push_back(member);
        };

        std::string serializeXML(){
            std::string listXML;
            for(auto member : _list){
                member.setListType(_type);
                listXML += member.serializeXML();
            }
            return listXML;
        };
};