#pragma once
#include <vector>
#include "MatrixEvent.h"
class MatrixAccountData {
    private : 
        std::vector<MatrixEvent> _events;
    public : 

        static MatrixAccountData deserializeJson(std::string json);

        std::vector<MatrixEvent> getEvents() {
            return _events;
        };

        void addEvent(MatrixEvent event){
            _events.push_back(event);
        };

        MatrixEvent getEventByType(std::string type) {
            for(auto event : _events) {
                if(event.getType() == type){
                    return event;
                }
            }
        return NULL;
        };
};