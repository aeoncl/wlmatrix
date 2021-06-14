#pragma once
#include "MatrixLeftRoom.h"

MatrixLeftRoom::MatrixLeftRoom(std::string id) : _id(id){};
MatrixLeftRoom::MatrixLeftRoom(){};

std::string MatrixLeftRoom::getId()
{
    return _id;
};

void MatrixLeftRoom::setId(std::string id)
{
    _id = id;
};
