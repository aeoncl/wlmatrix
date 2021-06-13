#include <exception>
#include <string>

class RestServiceException : public std::exception {

    public : 
        RestServiceException(const std::string msg) : exception(msg.c_str()) {};
};