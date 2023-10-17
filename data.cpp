//
// Created by maverick on 10/9/23.
//

#include "data.h"
#include "fstream"
data::data(std::string file_name) {
    std::ifstream din;


    din.open(file_name);
    if(!din.is_open()){
        throw   "No se ha podido abrir el archivo. ";
    }

    din.close();
}
