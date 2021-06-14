#pragma once
#include "pugixml.hpp"

class XMLStringWriter : pugi::xml_writer
{
    public:
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }

    std::string node_to_string(pugi::xml_node node) {
        
        node.print(*this);
        return result;
}
};