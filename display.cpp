//
// Created by maverick on 10/9/23.
//



#include "iostream"
#include "display.h"
void argument_menu(){
    std::cout << "Uso normal:\n"
                 "Procesador_inventario.exe [Argumentos] inventariofisico.csv\n"
                 "Argumentos posibles:\n"
                 "\t-total_art_dif --> Cantidad total de artículos diferentes.\n"
                 "\t-total_art --> Cantidad total de artículos.\n"
                 "\t-min_stock [n] --> Listado de artículos con cantidad n o menos de stock.\n"
                 "\t-min_stock [n],[deposito] --> Listado de artículos con cantidad n o menos de stock según un depósito.\n"
                 "\t-stock [nombre_articulo] --> El stock total del artículo ingresado como argumento.\n"
                 "\t-stock [nombre_articulo],[depósito] --> El stock del artículo en un depósito.\n"
                 "\t-max_Stock [n] --> Listado de aquellos artículos cuyo stock es igual o supera el número n.\n" << std::endl;
}

