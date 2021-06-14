#pragma once
#include "SoapResponse.h"

        std::string SoapResponse::getBody() {
            return _body;
        }

        int SoapResponse::getStatusCode() {
            return _statusCode;
        }