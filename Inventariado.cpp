#include "Inventariado.h"
#include "librerias/Cola/Cola.h"
#include "librerias/Arbol/ArbolBinarioAVL.h"

Inventariado::Inventariado(const std::string &file_name)
        : Data(file_name) {
}


void Inventariado::total_art_dif() {
    std::cout << "Total de articulos diferentes: " << m_file_number << std::endl;
}

void Inventariado::total_art() {
    Cola<unsigned int> count;
    unsigned int total=0;
    for(int i=0; i<m_file_number; i++){
        for(int j=3; j<m_column_number; j++){
            if(get_value(i,j)!="null"){
                count.encolar(str_num<unsigned int>(get_value(i,j)));
                //debug std::cout << "valor(" << i << "," << j << ")= " << str_num<unsigned int>(get_value(i,j)) << std::endl;
            }
        }
    }
    while (!count.esVacia()){
        total+=count.desencolar();
    }
    std::cout << "Total de articulos: " << total << std::endl;
}

void Inventariado::stock(char * nombre_articulo) {

}

void Inventariado::stock(char * nombre_articulo, unsigned int deposito) {

}

void Inventariado::min_stock(unsigned int n) {
    for (int i = 0; i < m_file_number; ++i) {
        get_value(i, m_column_number-2);
    }
}

void Inventariado::min_stock(unsigned int n, unsigned int deposito) {

}

void Inventariado::stock_max(unsigned int n) {

}
