//
// Created by maverick on 10/9/23.
//
//#include <cstring>
#include "ctime"
#include "iostream"
#include "display.h"
#include "Inventariado.h"

int  main(int argc, char **argv){

//  processador_inventario.exe -total_art_dif Inventario_fisico.csv
// usamos ctime para medir el timpo, se hace timando el tiempo inicial con t0
// cuando temrinamos de ejecutar el codigo que deseamos medir, tomamos el tiempp nuevamente con t1
// realizamos la resta y dividimos por CLOCKS_PER_SEC


/*
    unsigned t0, t1;
    try {
        std::string file_name = argv[argc - 1];

        //creacion del objeto Data, carga los valores del file_name a ram
        Inventariado obj_1(file_name);


        //TODO:menu\

        if (argc == 1) {
            argument_menu(argv);
        } else {
            t0 = clock();
            // codigo a ejecutar TODO:acomodar menu de argumentos
            char *arg_opt = argv[1];

            if (std::strcmp(arg_opt, "-total_art_dif") == 0) {
//                obj_1.test();
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
            } else if (std::strcmp(arg_opt, "-stock_2") == 0 && argc == 5) {
                int numeroDeposito = std::stoi(argv[3]); //convierte al argumento en int (no modifica el cod fuente)
                obj_1.stockEnDeposito("BANQUETA TAPIZADA COST BCO  BASE PINTADA NEGRO", numeroDeposito);
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
    */

    try {
        std::string file_name = argv[argc - 1];
        unsigned t0, t1;
        //creacion del objeto Data, carga los valores del file_name a ram
        Inventariado obj_1(file_name);

        std::unordered_map<std::string, int> arg_opt = {
                {"-total_art_dif", 1},
                {"-total_art",     2},
                {"-min_stock",     3},
                {"-stock",         4},
                {"-max_stock",     5}
        };
        t1 = clock();
        switch (arg_opt.find(argv[1])->second) {
            case 1: {
                obj_1.total_art_dif();
                break;
            }
            case 2: {
                obj_1.total_art();
                break;
            }
            case 3: {
                if (argc == 4) {
                    obj_1.min_stock(str_num<unsigned int>(argv[2]));
                } else if (argc == 5) {
                    obj_1.min_stock(str_num<unsigned int>(argv[2]), str_num<unsigned int>(argv[3]));
                }
                break;
            }
            case 4:{
                if (argc == 4) {
                    obj_1.stock(argv[2]);
                } else if (argc == 5) {
                    std::cout << "5 argumentos" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "-max_stock" << std::endl;
                break;
            }
            default: {
                argument_menu(argv);
                break;
            }
        }
        t1 = clock();

        std::cout << "\nTiempo de ejecucion: " << (double(t1 - t0) / CLOCKS_PER_SEC) << std::endl;
    }catch (const char *err){
        std::cout << "error: " << err << std::endl;
    }catch (const int err){
        std::cout << "error: " << err << std::endl;
    }
    return 0;
}