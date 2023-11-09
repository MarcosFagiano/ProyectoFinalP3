//
// Created by maverick on 11/6/23.
//

#ifndef PARCIAL2_V2_DATA_H
#define PARCIAL2_V2_DATA_H

#include <unordered_map>
#include <list>
#include "string"
#include "sstream"
#include "fstream"
#include "iostream"
class Data {
protected:
    std::string m_file_name;
    unsigned int m_column_number=0;
    unsigned int m_file_number=0;
    std::unordered_map<std::string, std::list<std::string>> m_data;
    std::list<std::string> m_hash_key;

    explicit Data(const std::string  &);
    ~Data();
    std::string get_element(unsigned int, unsigned int);
    std::string get_column(std::list<std::string> &o_list, unsigned int n);
    std::string get_value(std::string &o_str, unsigned int n);
};


#endif //PARCIAL2_V2_DATA_H
