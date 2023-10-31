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
        T aux;
        for(auto &x:str){
            x=='-'||x==' '?:aux+=(T)x;
        }
        T result = aux;

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
