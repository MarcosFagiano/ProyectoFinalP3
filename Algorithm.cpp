//
// Created by maverick on 10/23/23.
//

#include "Algorithm.h"

Algorithm::Algorithm(const std::string &file_name, char *&o_argv)
: Data(file_name) {

}

void Algorithm::print(int m, int n) {
    std::cout << get_element(m, n) << std::endl;
}

void Algorithm::total_art() {
    //std::cout << "Cantidad de articulos: " << m_data.size() << std::endl;
}

/*void Algorithm::total_art_dif() {
    unsigned int art_cont=0;
    for(int index=0; index<m_data.size(); index++){
        art_cont++;
    }
}*/
