//
// Created by maverick on 10/23/23.
//

#ifndef PARCIAL2_ALGORITHM_H
#define PARCIAL2_ALGORITHM_H


#include <vector>
#include <string>
#include "Data.h"
#include <iostream>
#include <typeinfo>
#include "librerias/Cola/Cola.h"

class Algorithm: protected Data {

public:
    Algorithm(const std::string &, char *&);
    void print(int,int);
    void total_art_dif();
    void total_art();

    void print(int m);
};


#endif //PARCIAL2_ALGORITHM_H
