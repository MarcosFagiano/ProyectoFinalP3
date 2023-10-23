//
// Created by maverick on 10/9/23.
//
#include <cstring>
#include "ctime"
#include "iostream"
#include "display.h"
#include "data.h"

int  main(int argc, char **argv){

// usamos ctime para medir el timpo, se hace timando el tiempo inicial con t0
// cuando temrinamos de ejecutar el codigo que deseamos medir, tomamos el tiempp nuevamente con t1
// realizamos la resta y dividimos por CLOCKS_PER_SEC

    unsigned t0, t1;
    std::string file_name="../Inventariado Fisico.csv";//test
    //std::string file_name=argv[argc-1];//final

    //creacion del objeto data, carga los valores del file_name a ram
    data d(file_name);

    t0=clock();
    // codigo a ejecutar TODO:

    d.print(3,1);

    /*if(argc==1){
        argument_menu(argv);
    }else{
        //data d(file_name);
        char *arg_opt = argv[1];
        if (std::strcmp(arg_opt, "-total_art_dif") == 0) {
            std::cout << "-total_art_dif" << std::endl;
        }else if (std::strcmp(arg_opt, "-total_art") == 0) {
            std::cout << "-total_art" << std::endl;
        }else if (std::strcmp(arg_opt, "-min_stock") == 0) {
            std::cout << "-min_stock" << std::endl;
        } else if (std::strcmp(arg_opt, "-min_stock") == 0 && argc == 5) {
            std::cout << "-min_stock_2" << std::endl;
        } else if (std::strcmp(arg_opt, "-stock") == 0) {
            std::cout << "-stock" << std::endl;
        } else if (std::strcmp(arg_opt, "-stock") == 0 && argc == 5) {
            std::cout << "-stock_2" << std::endl;
        } else if (std::strcmp(arg_opt, "-max_stock") == 0) {
            std::cout << "-max_stock" << std::endl;
        }
    }*/
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);

    std::cout << "\nTiempo de ejecucion: " << time << std::endl;

}