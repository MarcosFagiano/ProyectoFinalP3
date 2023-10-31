//
// Created by maverick on 10/9/23.
//



#include "Data.h"
#include "utils.h"

Data::Data(const std::string &file_name)
        : m_file_name{file_name} {

    std::ifstream din;
    din.open(file_name);
    if (!din.is_open()) {
        throw std::runtime_error("No se ha podido abrir el archivo.");
    }

    std::string raw_buffer;
    std::string raw_header;
    Lista<std::string> header;


    getline(din, raw_header);
    std::stringstream ss(raw_header);
    std::string header_buffer;
    while (getline(ss, header_buffer, ',')){
        header.insertarUltimo(header_buffer);
    }

    header_buffer.clear();
    raw_header.clear();
    m_depostit_number=header.getTamanio()-3;

    //Lista<std::string> element_buffer;
    while (std::getline(din, raw_buffer)) {
        std::stringstream stringStream(raw_buffer);
        Lista<std::string> element_buffer;
        std::string element;

        while(std::getline(stringStream, element, ',')){
            element_buffer.insertarUltimo(element);
        }
        m_hash_key.insertarUltimo(str_num<unsigned int>(element_buffer.getDato(1)));
        m_data.emplace(m_hash_key.getDato(m_hash_key.getTamanio()-1), raw_buffer);
        raw_buffer.clear();
        element.clear();
        element_buffer.vaciar();
    }
    din.close();


}


void Data::save_report() {

};

Data::~Data(){
    save_report();
}

std::string Data::get_element(int m, int n) {
    std::string str_in= m_data.find(m_hash_key.getDato(m))->second, aux_buffer;
    Lista<std::string> aux;
    std::stringstream ss(str_in);
    while (getline(ss, aux_buffer, ',')){
        aux.insertarUltimo(aux_buffer);
    }
    return aux.getDato(n);
}

std::string Data::get_row(int m) {
    return m_data.find(m_hash_key.getDato(m))->second;
}
