//
// Created by maverick on 10/9/23.
//
#include "ctime"
#include "iostream"
#include "display.h"
#include "data.h"

int  main(int argc, char **argv){
// usamos ctime para medir el timpo, se hace timando el tiempo inicial con t0
// cuando temrinamos de ejecutar el codigo que deseamos medir, tomamos el tiempp nuevamente con t1
// realizamos la resta y dividimos por CLOCKS_PER_SEC
    unsigned t0, t1;
    t0=clock();
    // codigo a ejecutar TODO:empezaer el proyecto ray

    if(argc==1){
        argument_menu();
        std::string file_name="../Inventariado Fisico.csv";
        try{
            data d(file_name);
        }catch (char const *err){
            std::cout << err << std::endl;
        }
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);

    std::cout << "\nTiempo de ejecucion: " << time << std::endl;

}