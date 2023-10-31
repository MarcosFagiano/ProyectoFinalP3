//
// Created by maverick on 10/23/23.
//

#include "Algorithm.h"
#include "utils.h"

Algorithm::Algorithm(const std::string &file_name)
        : Data(file_name) {

}

void Algorithm::print(int m) {
    std::cout << m_data.find(m_hash_key.getDato(m))->second << std::endl;
}

void Algorithm::total_art() {
    std::cout << "El total de articulos es: " << m_hash_key.getTamanio() << std::endl;
}

void Algorithm::total_art_dif() {
    Cola<unsigned int> cola;
    unsigned int total=0;
    for (int j = 0; j < m_hash_key.getTamanio()-1; j++) {
        for(int i=3; i<m_depostit_number+2;i++) {
//debug            std::cout << typeid(Data::get_element(j, i)).name() << std::endl;
//debug            std::cout << str_num<unsigned int>(Data::get_element(j, i))<<std::endl;
            cola.encolar(str_num<unsigned int>((Data::get_element(j,i))));
        }
    }
    while (!cola.esVacia()){
        total+=cola.desencolar();
    }
    std::cout << "La cantidad total de articulos es: " << total << std::endl;
}

