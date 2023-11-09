cmake_minimum_required(VERSION 3.26)
project(parcial2_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Procesador_inventario main.cpp
        Inventariado.cpp
        Data.cpp
        utils.h
        display.h
)