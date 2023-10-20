//
// Created by maverick on 10/9/23.
//

#include <sstream>
#include "data.h"
#include "fstream"
data::data(std::string file_name) {
    std::ifstream din;
    std::string buffer_linea;
//    Lista<Lista<std::string>> data;
    std::string header;
    Lista<std::string> data;

    din.open(file_name);
    if(!din.is_open()){
        throw   "No se ha podido abrir el archivo. ";
    }
    getline(din, header);

    std::cout <<  header;

    Lista<std::string> fila;
    while (std::getline(din, buffer_linea)){
        //std::stringstream stringStream(buffer_linea);
        //      std::string valor;

/*        while(std::getline(stringStream, valor, ',')){
            */fila.insertarUltimo(buffer_linea);/*
        }
        data.insertarPrimero(fila);*/
    }

    fila.print();
    din.close();
}


