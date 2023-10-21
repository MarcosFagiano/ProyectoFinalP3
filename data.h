//
// Created by maverick on 10/9/23.
//

#ifndef PARCIAL2_DATA_H
#define PARCIAL2_DATA_H

#include <string>
#include "librerias/Lista/Lista.h"
class data {
private:
    const unsigned int MAX_CHAR = 196;
    std::string m_file_name;
    struct product{
        char *m_group=nullptr;
        char *m_bar_code=nullptr;
        char *m_article=nullptr;
        unsigned int m_store_1{};
        unsigned int m_store_2{};
        unsigned int m_store_3{};
        unsigned int m_store_4{};
        unsigned int m_store_5{};
    };

public:
    explicit data(const std::string&);
    ~data();

    void save_report();

};


#endif //PARCIAL2_DATA_H
