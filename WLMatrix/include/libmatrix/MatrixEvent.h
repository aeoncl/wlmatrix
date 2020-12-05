#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <any>
#include "IMatrixEvent.h"

class MatrixEvent {

    private :
        std::string _type;
        std::unordered_map<std::string, std::any> _content;

    public :
        MatrixEvent(){};
        MatrixEvent(std::string type) : _type(type){};

        void deserializeJson(std::string json);

        std::string getType() {
            return _type;
        };

        template <class T>
        T getProperty(std::string name) {
            return std::any_cast<T>(_content.at(name));
        };

        template <class T>
        void setProperty(std::string name, T value) {
            _content.emplace(name, std::make_any<T>(value));
        };

};