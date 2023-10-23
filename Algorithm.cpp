//
// Created by maverick on 10/23/23.
//

#include "Algorithm.h"

Algorithm::Algorithm(const std::string &file_name, char *&o_argv)
: Data(file_name, o_argv) {

}

void Algorithm::print() {
    std::cout << m_data[3][4] << std::endl;

}

