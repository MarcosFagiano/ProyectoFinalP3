//
// Created by maverick on 10/9/23.
//
#include <cstring>
#include "ctime"
#include "iostream"
#include "display.h"
//#include "utils.h"
#include "Algorithm.h"
//#include "librerias/HashMap/HashEntry.h"

int  main(int argc, char **argv){

//  processador_inventario.exe -total_art_dif Inventario_fisico.csv
// usamos ctime para medir el timpo, se hace timando el tiempo inicial con t0
// cuando temrinamos de ejecutar el codigo que deseamos medir, tomamos el tiempp nuevamente con t1
// realizamos la resta y dividimos por CLOCKS_PER_SEC

    unsigned t0, t1;
    try {
        std::string file_name = argv[argc - 1];

        //creacion del objeto Data, carga los valores del file_name a ram
        Algorithm obj_1(file_name);


        //TODO:menu\

        if (argc == 1) {
            argument_menu(argv);
        } else {
            t0 = clock();
            // codigo a ejecutar TODO:acomodar menu de argumentos
            char *arg_opt = argv[1];

            if (std::strcmp(arg_opt, "-total_art_dif") == 0) {
                obj_1.test();
                obj_1.total_art_dif();
            } else if (std::strcmp(arg_opt, "-total_art") == 0) {
                obj_1.total_art();
            } else if (std::strcmp(arg_opt, "-min_stock") == 0) {
                std::cout << "-min_stock" << std::endl;
            } else if (std::strcmp(arg_opt, "-min_stock") == 0 && argc == 5) {
                std::cout << "-min_stock_2" << std::endl;
            } else if (std::strcmp(arg_opt, "-stock") == 0) {
                obj_1.stock("BANQUETA TAPIZADA COST BCO  BASE PINTADA NEGRO");
                std::cout << "-stock" << std::endl;
            } else if (std::strcmp(arg_opt, "-stock") == 0 && argc == 5) {
                int numeroDeposito = std::stoi(argv[4]);
                obj_1.stockEnDeposito("BANQUETA TAPIZADA COST BCO  BASE PINTADA NEGRO", 3);
                std::cout << "-stock_2" << std::endl;
            } else if (std::strcmp(arg_opt, "-max_stock") == 0) {
                std::cout << "-max_stock" << std::endl;
            }
            t1 = clock();
        }
    }catch (const char *err){
        std::cout << "error: " << err << std::endl;
    }catch (const int err){
        std::cout << "error: " << err << std::endl;
    }
    double time = (double (t1-t0)/CLOCKS_PER_SEC);

    std::cout << "\nTiempo de ejecucion: " << time << std::endl;

}