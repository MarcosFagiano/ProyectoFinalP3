#include "Inventariado.h"
#include "librerias/Cola/Cola.h"
#include "librerias/Arbol/ArbolBinarioAVL.h"

Inventariado::Inventariado(const std::string &file_name)
        : Data(file_name){
}


void Inventariado::total_art_dif() {
    std::cout << "Total de articulos diferentes: " << m_file_number << std::endl;
}

void Inventariado::total_art() {
    unsigned int total=0;
    for(int i=0; i<m_file_number; i++){
        for(int j=3; j<=m_column_number; j++){
            if(isdigit(get_element(i, j)[0]) && !get_element(i, j).empty()){
                std::cout << "valor(" << i+1 << "," << j+1 << ")= " << std::stoul(get_element(i, j)) << std::endl;
                total+=std::stoul(get_element(i, j));
            }
        }
    }
    std::cout << "Total de articulos: " << total << std::endl;
}

void Inventariado::min_stock(unsigned int n) {

}

void Inventariado::min_stock(unsigned int n, unsigned int deposito) {

}


void Inventariado::max_stock(unsigned int n) {

}

void Inventariado::stock(const char *nombreArticulo) {
    std::string buffer(nombreArticulo);
    unsigned int suma=0;
    for(int i=3; i<m_column_number; i++){
        auto buffer_str = get_value(buffer, i);
        suma+= isdigit(buffer_str[0])?std::stoul(buffer_str):0;
        buffer_str.clear();
    }
    std::cout << "El stock de " << nombreArticulo << " es: " << suma << std::endl;
}

void Inventariado::stock(const char *nombreArticulo, unsigned int numeroDeposito) {
    numeroDeposito+=3;
    if(numeroDeposito<3||numeroDeposito>m_column_number){
        throw std::runtime_error("Deposito fuera de rango.");
    }
    std::string buffer(nombreArticulo);
    auto buffer_str = get_value(buffer, numeroDeposito);
    std::cout <<"El stock de " << nombreArticulo << " es: "<<
              (isdigit(buffer_str[0])?std::stoul(buffer_str):0) << std::endl;
}

void Inventariado::test(){
    for(int i=0; i<m_file_number; i++){
        std::cout << get_element(i, 7) << std::endl;
    }
}