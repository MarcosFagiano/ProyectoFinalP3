cmake_minimum_required(VERSION 3.26)
project(parcial2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Procesador_inventario
        main.cpp
        display.cpp
        Data.h
        Data.cpp
        display.h
        Algorithm.h
        Algorithm.cpp
        utils.h)
