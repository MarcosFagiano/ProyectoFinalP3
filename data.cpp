//
// Created by maverick on 10/9/23.
//

#include <sstream>
#include <vector>
#include "data.h"
#include "fstream"

data::data(const std::string& file_name){

    std::ifstream din;
    std::string buffer_linea;
    std::vector<std::string> data;
    std::string header;

    m_file_name=file_name;

    din.open(file_name);
    if (!din.is_open()) {
        throw "No se ha podido abrir el archivo. ";
    }
    getline(din, header);
    std::cout << header;

    std::vector<std::string> fila;
    while (std::getline(din, buffer_linea)) {
        std::stringstream stringStream(buffer_linea);
              std::string valor;

        while(std::getline(stringStream, valor, ',')){
            fila.push_back(buffer_linea);
        }
        data.push_back();
    }
    din.close();
}

void data::save_report() {

};

data::~data(){
    save_report();
}


