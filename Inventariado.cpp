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
        for(int j=3; j<m_column_number; j++){
            if(isdigit(get_value(i,j)[0])&& !get_value(i,j).empty()){
                std::cout << "valor(" << i << "," << j << ")= " <<  std::stoul(get_value(i,j)) << std::endl;
                total+=std::stoul(get_value(i,j));
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

}

void Inventariado::stock(const char *nombreArticulo, unsigned int numeroDeposito) {

}

void Inventariado::test(){
    for(int i=0; i<m_file_number; i++){
        std::cout << get_value(i, 7) << std::endl;
    }
}