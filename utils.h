//
// Created by maverick on 10/24/23.
//

#ifndef PARCIAL2_UTILS_H
#define PARCIAL2_UTILS_H

#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <list>

template<class T>
T str_num(std::string const &str) {
    T aux=0;
    if(str.empty()){
        return 0;
    }else {
        for (auto &x: str) {
            x == '-' || x == ' ' ?: aux += (T) x;
        }
        T result = aux;

        if (result > std::numeric_limits<T>::max()) {
            throw std::out_of_range("Fuera de rango.");
        }
        return result-'0';
    }
}

template<class T>
T str_num(const char * str) {
    T value;
    std::istringstream stream(str);
    stream >> value;
    return value;
}

#endif //PARCIAL2_UTILS_H
