#pragma once
#include "RestServiceException.h"

RestServiceException::RestServiceException(const std::string msg) : exception(msg.c_str()) {};
