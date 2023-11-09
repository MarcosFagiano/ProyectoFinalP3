//
// Created by maverick on 11/6/23.
//

#ifndef PARCIAL2_V2_INVENTARIADO_H
#define PARCIAL2_V2_INVENTARIADO_H

#include <vector>
#include <string>
#include "Data.h"
#include <iostream>
#include <typeinfo>
#include "utils.h"
#include "librerias/Lista/Lista.h"
#include "librerias/Arbol/ArbolBinarioAVL.h"

class Inventariado: protected Data {
public:
    explicit Inventariado(const std::string &);
    void total_art_dif();
    void total_art();
    void min_stock(unsigned int );
    void min_stock(unsigned int, unsigned int);
    void max_stock(unsigned int);

    void stock(const char *nombreArticulo, unsigned int numeroDeposito);
    void stock(const char *nombreArticulo);

};





#endif //PARCIAL2_V2_INVENTARIADO_H
