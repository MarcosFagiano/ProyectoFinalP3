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

class data {
private:
    const unsigned int MAX_CHAR = 196;
    std::string m_file_name;
    unsigned int m_depostit_number;
    std::vector<std::vector<std::string>> m_data;



public:
    explicit data(const std::string&);
    ~data();

    void save_report();
    void print(int,int);
    //friend &std::ostream operator<<(std::ostream &os, T& obj);

};


#endif //PARCIAL2_DATA_H
