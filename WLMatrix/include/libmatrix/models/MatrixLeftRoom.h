#pragma once
#include <string>
#include <vector>
#include "MatrixEvent.h"

class MatrixLeftRoom
{
private:
    std::string _id;
    std::vector<MatrixEvent> _timeline;
    std::vector<MatrixEvent> _state;
    std::vector<MatrixEvent> _ephemeral;

public:
    MatrixLeftRoom(std::string id);
    MatrixLeftRoom();

    std::string getId();

    void setId(std::string id);
};