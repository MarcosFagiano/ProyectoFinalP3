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

template<typename T>
T str_num(std::string str) {
    T result;

    result = std::stoi(str);

    if (result > std::numeric_limits<T>::max()) {
        throw std::out_of_range("Fuera de rango.");
    }

    return result;
}

template<class T>
T get_list_element(std::list<T> const &o_list, int index){
    auto it = o_list.begin();
    std::advance(it, index);
    return *it;
}


#endif //PARCIAL2_UTILS_H
