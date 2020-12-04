#pragma once
#include <string>
#include <vector>
#include "MatrixEvent.h"
class MatrixRoom {
    private : 
        std::string _id;
        std::vector<MatrixEvent> _events;
    public :
        MatrixRoom(std::string id) : _id(id) {};
        MatrixRoom() {};
        
        std::string getId() {
            return _id;
        }

        void setId(std::string id) {
            _id = id;
        }
}; 