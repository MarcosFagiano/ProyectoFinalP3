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
#include "librerias/Arbol/ArbolBinarioAVL.h"


class Algorithm: protected Data {
private:
    ArbolBinarioAVL<std::string> arbinventario;
public:
    Algorithm(const std::string &);
    void print(int,int);
    void total_art_dif();
    void total_art();
    void stock(const std::string &nombreArticulo);
    void stockEnDeposito(const std::string &nombreArticulo, int numeroDeposito);

    void print(int m);

    void test();
};


#endif //PARCIAL2_ALGORITHM_H
