#pragma once
#include "MSNMembershipList.h"

void MSNMembershipList::addMember(MSNMember member) {
            _list.push_back(member);
        };

        std::string MSNMembershipList::serializeXML(){
            std::string listXML;
            for(auto member : _list){
                member.setListType(_type);
                listXML += member.serializeXML();
            }
            return listXML;
        };