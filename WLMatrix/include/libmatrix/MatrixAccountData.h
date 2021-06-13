#pragma once
#include <vector>
#include "MatrixEvent.h"
#include <optional>

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

        std::optional<MatrixEvent> getEventByType(std::string type) {
            for(auto event : _events) {
                if(event.getType() == type){
                    return std::make_optional(event);
                }
            }
        return std::nullopt;
        };
};