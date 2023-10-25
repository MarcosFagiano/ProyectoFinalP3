//
// Created by maverick on 10/23/23.
//

#ifndef PARCIAL2_ALGORITHM_H
#define PARCIAL2_ALGORITHM_H


#include <vector>
#include <string>
#include "Data.h"
#include "utils.h"
#include <iostream>
#include <typeinfo>

class Algorithm: protected Data {

public:
    Algorithm(const std::string &, char *&);
    void print(int,int);

};


#endif //PARCIAL2_ALGORITHM_H
