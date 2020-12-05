#pragma once
#include <string>
#include <vector>
#include "MatrixEvent.h"

class MatrixInvitedRoom {
    private : 
        std::string _id;
        std::vector<MatrixEvent> _state;

    public :
        MatrixInvitedRoom(std::string id) : _id(id) {};
        MatrixInvitedRoom() {};
        
        std::string getId() {
            return _id;
        };

        void setId(std::string id) {
            _id = id;
        };
}; 