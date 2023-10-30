//
// Created by maverick on 10/23/23.
//

#include "Algorithm.h"
#include "utils.h"

Algorithm::Algorithm(const std::string &file_name, char *&o_argv)
: Data(file_name) {

}

void Algorithm::print(int m, int n) {
    auto list =  get_element(m, n);
    for(auto &x:list){
        std::cout << x << ',';
    }
    std::cout << std::endl;
    list.clear();
}
void Algorithm::print(int m) {
    auto hash_key =  get_list_element(m_hash_key,m);
    auto list = m_data.find(hash_key);
    for(auto &x:list->second){
        std::cout << x << ',';
    }
    std::cout << std::endl;
}

void Algorithm::total_art() {
    //std::cout << "Cantidad de articulos: " << m_data.size() << std::endl;
}

void Algorithm::total_art_dif() {

}
