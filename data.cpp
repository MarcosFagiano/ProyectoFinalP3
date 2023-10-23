//
// Created by maverick on 10/9/23.
//



#include "data.h"
data::data(const std::string& file_name)
        :m_file_name{file_name}{

    std::ifstream din;
    din.open(file_name);
    if (!din.is_open()) {
        throw "No se ha podido abrir el archivo. ";
    }

    std::string raw_buffer;
    std::string raw_header;
    std::vector<std::string> header;


    getline(din, raw_header);
    std::stringstream ss(raw_header);
    std::string header_buffer;
    while (getline(ss, header_buffer, ',')){
        header.push_back(header_buffer);
    }

    header_buffer.clear();
    raw_header.clear();
    m_depostit_number=header.size()-3;
    std::cout << m_depostit_number << std:: endl;

    std::vector<std::string> row_buffer;
    while (std::getline(din, raw_buffer)) {
        std::stringstream stringStream(raw_buffer);
        std::string element;

        while(std::getline(stringStream, element, ',')){
            row_buffer.push_back(element);
        }
        m_data.push_back(row_buffer);
        row_buffer.clear();
        raw_buffer.clear();
        element.clear();
    }
    din.close();
}

void data::save_report() {

};

data::~data(){
    save_report();
}

void data::print(int m, int n) {
    std::cout << m_data[m][n] << std::endl;
}




