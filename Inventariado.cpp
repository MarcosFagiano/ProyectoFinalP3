#include "Inventariado.h"
#include "librerias/Arbol/ArbolBinarioAVL.h"

Inventariado::Inventariado(const std::string &file_name)
        : Data(file_name){
}


void Inventariado::total_art_dif() {
    std::cout << "Total de articulos diferentes: " << m_file_number << std::endl;
}

void Inventariado::total_art() {
    unsigned int total=0;
    for(int i=0; i<m_file_number; i++){
        for(int j=3; j<=m_column_number; j++){
            if(isdigit(get_element(i, j)[0]) && !get_element(i, j).empty()){
                std::cout << "valor(" << i+1 << "," << j+1 << ")= " << std::stoul(get_element(i, j)) << std::endl;
                total+=std::stoul(get_element(i, j));
            }
        }
    }
    std::cout << "Total de articulos: " << total << std::endl;
}

void Inventariado::min_stock(unsigned int n) {
    auto stock =new Lista<int>;
    auto name=new Lista<std::string>;
    unsigned int total = 0;
    unsigned int suma = 0;
    for(int i=0;i<m_file_number;i++){
        total = 0;

        for(int j=3; j<m_column_number; j++){
            suma = 0;
            if(isdigit(get_element(i, j)[0]) && !get_element(i, j).empty()){

                suma = std::stoul(get_element(i, j));
                total += suma;
            }
        }
        stock->insertarUltimo(total);
        name->insertarUltimo(get_element(i,2));
    }
    stock->quickSort(0,stock->getTamanio()-1,stock,name);

    int pos;

    pos=stock->pos_min(n);

    if(pos>-1){
        std::cout<<"Listado de articulos con cantidad n o menos de stock: \n";
        stock->print_min(pos,name,stock);
    }else{
        std::cout<<"No se encontro ningun articulo.\n";
    }
}

void Inventariado::min_stock(unsigned int n, unsigned int numeroDeposito) {
    numeroDeposito+=2;
    if(numeroDeposito<3||numeroDeposito>m_column_number){
        throw "Deposito fuera de rango.";
    }

    auto stock = new Lista<int>;
    auto name = new Lista<std::string>;

    unsigned int suma = 0;

    for (int i = 0; i < m_file_number; i++) {
        suma = 0;
        if (isdigit(get_element(i, numeroDeposito)[0]) && !get_element(i, numeroDeposito).empty()) {
            suma = std::stoul(get_element(i, numeroDeposito));
        }
        stock->insertarUltimo(suma);
        name->insertarUltimo(get_element(i, 2));
    }
    stock->quickSort(0, stock->getTamanio() - 1, stock, name);

    int aux;
    aux=stock->pos_min(n);

    if(aux!=-1){
        std::cout<<"Listado de articulos con cantidad n o menos de stock segun un numeroDeposito:\n";
        stock->print_min(aux,name,stock);
    }else {
        std::cout << "No se encontro ningun articulo.\n";
    }


    delete stock;
    delete name;
}



void Inventariado::max_stock(unsigned int n) {

    auto stock = new Lista<int>;
    auto name = new Lista<std::string>;
    unsigned int total = 0;
    unsigned int suma = 0;
    for(int i=0;i<m_file_number;i++){
        total = 0;
        for(int j=3; j<m_column_number; j++){
            suma = 0;
            if(isdigit(get_element(i, j)[0]) && !get_element(i, j).empty()){
                suma = std::stoul(get_element(i, j));
                total += suma;
            }
        }
        stock->insertarUltimo(total);
        name->insertarUltimo(get_element(i,2));
    }

    stock->quickSort(0,stock->getTamanio()-1,stock,name);

    int pos;

    pos=stock->pos_max(n);

    if(pos!=-1){
        std::cout<<"Listado de articulos con cantidad n o mayor de stock: \n";
        stock->print_max(pos,name,stock);
    }else{
        std::cout<<"No se encontro ningun articulo.\n";
    }
    delete stock;
    delete name;
}

void Inventariado::stock(const char *nombreArticulo) {
    std::string buffer(nombreArticulo);
    unsigned int suma=0;
    for(int i=3; i<m_column_number; i++){
        auto buffer_str = get_value(buffer, i);
        suma+= isdigit(buffer_str[0])?std::stoul(buffer_str):0;
        buffer_str.clear();
    }
    std::cout << "El stock de " << nombreArticulo << " es: " << suma << std::endl;
}

void Inventariado::stock(const char *nombreArticulo, unsigned int numeroDeposito) {
    numeroDeposito+=2;
    if(numeroDeposito<3||numeroDeposito>m_column_number){
        throw "Deposito fuera de rango.";
    }
    std::string buffer(nombreArticulo);
    auto buffer_str = get_value(buffer, numeroDeposito);
    std::cout <<"El stock de " << nombreArticulo << " es: "<<
              (isdigit(buffer_str[0])?std::stoul(buffer_str):0) << std::endl;
}
