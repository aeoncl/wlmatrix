#include "SoapEndpointHandlerFactory.h"
#include "SoapEndpointHandlers.h"

const ISoapEndpointHandler* SoapEndpointHandlerFactory::getHandler(std::string requestPath){
	for(auto handler : _handlers){
        if(handler.first._Starts_with(requestPath)){
            return handler.second;
        }
    }
    return _handlers.at("empty");
}

const std::unordered_map<std::string, const ISoapEndpointHandler*> SoapEndpointHandlerFactory::_handlers = {
    {"/RST2.srf", new RST2()},
    {"/abservice/SharingService.asmx", new SharingService()},
    {"/abservice/abservice.asmx", new AbService()},
    {"empty", new SoapEmpty()}
};