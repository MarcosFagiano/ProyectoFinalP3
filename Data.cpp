//
// Created by maverick on 11/6/23.
//

#include <vector>
#include "Data.h"

Data::Data(const std::string &file_name)
        :m_file_name(file_name) {
    std::ifstream din;
    din.open(file_name);
    if (!din.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo.");
    }

    std::string input_buffer, input_header, aux_buffer, input_row;
    std::list<std::string> header, aux_map;

    getline(din, input_header);
    std::stringstream ih(input_header);

    //guardamos la primer linea (cabecera) y separamos por coma almacenando los valores en una lista.
    while (getline(ih, aux_buffer, ',')){
        header.push_back(aux_buffer);
        m_column_number++;
    }

    input_buffer.clear();
    aux_buffer.clear();
    while (getline(din, input_row)) {
        std::stringstream ir(input_row);
        while (getline(ir, aux_buffer, ',')) {
            if (!aux_buffer.empty()) {
                aux_map.push_back(aux_buffer);
            } else {
                aux_map.emplace_back("null");
            }
        }
        if (input_row.back() == ',') {
            aux_map.emplace_back("null");
        }
        ir.clear();
        //guardamos la fila de entrada en n hashmap con m_hash_key[1] como llave.
        //m_hash_key[1] contiene el codigo de barras del producto
        m_hash_key.push_back(get_key(aux_map, 2));
        m_data.emplace(m_hash_key.back(), aux_map);
        m_file_number++;
        aux_map.clear();
        input_row.clear();
        aux_buffer.clear();
    }
    din.close();
}

/*std::string Data::get_element(unsigned int n, unsigned int m) {

    return std::string();
}*/

std::string Data::get_key(std::list<std::string> &o_list, unsigned int n) {
    auto it = o_list.begin();
    std::advance(it, n);
    return *it;
}

std::string Data::get_value(unsigned int n, unsigned int m) {

    if(m==m_column_number-1){
        auto it_n = m_hash_key.begin();
        std::advance(it_n, n);
        auto it_m = m_data.find(*it_n)->second.back();
        return it_m;
    }else {
        auto it_n = m_hash_key.begin();
        std::advance(it_n, n);
        auto it_m = m_data.find(*it_n)->second.begin();
        std::advance(it_m, m);
        return *it_m;
    }
}

Data::~Data() = default;



