#pragma once
#include "MatrixInvitedRoom.h"

 MatrixInvitedRoom::MatrixInvitedRoom(std::string id): _id(id){};
        MatrixInvitedRoom::MatrixInvitedRoom(){
        };
        
        std::string MatrixInvitedRoom::getId() {
            return _id;
        };

        void MatrixInvitedRoom::setId(std::string id) {
            _id = id;
        };