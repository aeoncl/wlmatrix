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
        MatrixJoinedRoom(std::string id) : _id(id) {};
        MatrixJoinedRoom() {};

        static MatrixJoinedRoom deserializeJson(std::string json);

        
        std::string getId() {
            return _id;
        };

        void setId(std::string id) {
            _id = id;
        };

        void addStateEvent(MatrixEvent event) {
            _state.push_back(event);
        }

        void addTimelineEvent(MatrixEvent event) {
            _timeline.push_back(event);
        }

        std::vector<MatrixEvent> getStateEventsForType(std::string type){
            std::vector<MatrixEvent> out;
            for(auto event : _state){
                if(event.getType() == type){
                    out.push_back(event);
                }
            }
            return out;
        }

        bool containsInvitedMember() {
            for(auto stateEvent : _state){
                if(stateEvent.getType() == "m.room.member" && stateEvent.getProperty<std::string>("membership") == "join"){
                    return true;
                }
            }
            return false;
        }
}; 