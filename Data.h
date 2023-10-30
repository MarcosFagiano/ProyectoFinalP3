//
// Created by maverick on 10/9/23.
//

#ifndef PARCIAL2_DATA_H
#define PARCIAL2_DATA_H

#include <string>
#include <sstream>
#include <vector>
#include "fstream"
#include <iostream>
#include "librerias/Lista/Lista.h"
#include "librerias/HashMap/HashMap.h"

class Data{
protected:
    std::string m_file_name;
    unsigned int m_depostit_number;
    HashMap<std::string, Lista<std::string>> m_data;
    Lista<std::string> m_hash_key;

    Data(const std::string &);
    ~Data();

    void save_report();
    std::string get_element(int, int);

};


#endif //PARCIAL2_DATA_H
