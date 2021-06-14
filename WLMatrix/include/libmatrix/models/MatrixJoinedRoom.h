#pragma once
#include <string>
#include <vector>
#include "MatrixEvent.h"

class MatrixJoinedRoom {
    private : 
        std::string _id;
        std::vector<MatrixEvent> _timeline;
        std::vector<MatrixEvent> _state;
        std::vector<MatrixEvent> _ephemeral;

    public :
        MatrixJoinedRoom(std::string id);
        MatrixJoinedRoom();
        static MatrixJoinedRoom deserializeJson(std::string json);
        std::string getId();
        void setId(std::string id);
        void addStateEvent(MatrixEvent event);
        void addTimelineEvent(MatrixEvent event);
        std::vector<MatrixEvent> getStateEventsForType(std::string type);
        bool containsInvitedMember();
}; 