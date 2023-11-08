#include "Inventariado.h"
#include "librerias/Cola/Cola.h"
#include "librerias/Arbol/ArbolBinarioAVL.h"

Inventariado::Inventariado(const std::string &file_name)
        : Data(file_name) {
}

void Inventariado::print(int m) {
    std::cout << get_value(1,1) << std::endl;
}

void Inventariado::test(){
    //std::cout << m_data.find(get_key(m_hash_key, 2))->second.back() << std::endl;
    std::cout << get_value(3,0) << std::endl;
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

void Inventariado::stock(char * articulo) {

}

void Inventariado::min_stock(unsigned int n) {
    ArbolBinarioAVL<std::list<std::string>> arbol;

    arbol.put(m_data.find(m_hash_key.back())->second);

}

void Inventariado::min_stock(unsigned int n, unsigned int deposito) {

}
