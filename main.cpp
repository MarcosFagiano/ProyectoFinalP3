//
// Created by maverick on 10/9/23.
//
#include "ctime"
#include "iostream"
#include "display.h"
#include "Inventariado.h"

int  main(int argc, char **argv){

// processador_inventario.exe [argumentos] Inventariado_Fisico.csv
// usamos ctime para medir el timpo, se hace timando el tiempo inicial con t0
// cuando temrinamos de ejecutar el codigo que deseamos medir, tomamos el tiempp nuevamente con t1
// realizamos la resta y dividimos por CLOCKS_PER_SEC

    try {
        std::string file_name = argv[argc - 1];
        unsigned t0, t1;
        //creacion del objeto Data, carga los valores del file_name a ram
        if(argc==1){
            argument_menu(argv);
        }else {
            Inventariado obj_1(file_name);
            std::unordered_map<std::string, int> arg_opt = {
                    {"-total_art_dif", 1},
                    {"-total_art",     2},
                    {"-min_stock",     3},
                    {"-stock",         4},
                    {"-max_stock",     5}
            };
            t0 = clock();
            switch (arg_opt.find(argv[1])->second) {
                case 1: {
                    obj_1.total_art_dif();
                    break;
                }
                case 2: {
                    obj_1.total_art();
                    //obj_1.test();
                    break;
                }
                case 3: {
                    if (argc == 4) {
                        obj_1.min_stock(str_num<unsigned int>(argv[2]));
                    } else if (argc == 5) {
                        obj_1.min_stock(str_num<unsigned int>(argv[2]), str_num<unsigned int>(argv[3]));
                    }else{
                        argument_menu(argv);
                    }
                    break;
                }
                case 4: {
                    if (argc == 4) {
                        obj_1.stock(argv[2]);
                    } else if (argc == 5) {
                        obj_1.stock(argv[2], str_num<unsigned int>(argv[3]));
                    }else{
                        argument_menu(argv);
                    }
                    break;
                }
                case 5: {
                    obj_1.max_stock(str_num<unsigned int>(argv[2]));
                    break;
                }
                default: {
                    argument_menu(argv);
                    break;
                }
            }
            t1 = clock();
        }
        std::cout << "\nTiempo de ejecucion: " << (double(t1 - t0) / CLOCKS_PER_SEC) << std::endl;
    }catch (const char *err){
        std::cout << "error: " << err << std::endl;
    }catch (const int err){
        std::cout << "error: " << err << std::endl;
    }

    return 0;
}