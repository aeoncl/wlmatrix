#pragma once
#include "ISoapEndpointHandler.h"
#include <unordered_map>
class SoapEndpointHandlerFactory {
	private :
		const static std::unordered_map<std::string, const ISoapEndpointHandler*> _handlers;
	public : 
		const static ISoapEndpointHandler* getHandler(std::string requestPath);
};