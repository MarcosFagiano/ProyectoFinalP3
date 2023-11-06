cmake_minimum_required(VERSION 3.26)
project(parcial2)

set(CMAKE_CXX_STANDARD 14)
add_executable(Procesador_inventario
        main.cpp
        Data.cpp
        display.cpp
        Algorithm.cpp
        utils.h
        librerias/HashMap/HashMap.h
        librerias/Arbol/ArbolBinarioAVL.h
        librerias/Lista/Lista.h
        librerias/Arbol/ArbolBinario.h)
