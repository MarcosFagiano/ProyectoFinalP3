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
class Data{
protected:
    const unsigned int MAX_CHAR = 196;
    std::string m_file_name;
    unsigned int m_depostit_number;
    std::string m_argv;
    std::vector<std::vector<std::string>> m_data;



public:
    Data(const std::string &, char* &);
    ~Data();

    void save_report();
    std::string get_element(int, int);

};


#endif //PARCIAL2_DATA_H
