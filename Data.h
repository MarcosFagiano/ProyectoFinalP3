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
#include "unordered_map"
#include "list"

class Data{
protected:
    std::string m_file_name;
    unsigned int m_depostit_number;
    std::unordered_map<std::string, std::list<std::string>> m_data;
    std::list<std::string> m_hash_key;

    Data(const std::string &);
    ~Data();

    void save_report();
    std::string get_element(int, int);


    std::list<std::string> get_row(int m);
};


#endif //PARCIAL2_DATA_H
