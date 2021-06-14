#pragma once
#include <vector>
#include "MatrixEvent.h"
#include <optional>

class MatrixAccountData {
    private : 
        std::vector<MatrixEvent> _events;
    public : 

        static MatrixAccountData deserializeJson(std::string json);

        std::vector<MatrixEvent> getEvents();

        void addEvent(MatrixEvent event);

        std::optional<MatrixEvent> getEventByType(std::string type);
};