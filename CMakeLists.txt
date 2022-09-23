cmake_minimum_required(VERSION 3.21)
project(El_eterno_dilema_del_lector)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS " -Wall -Werror" )

add_executable(El_eterno_dilema_del_lector main.cpp Menu.cpp Menu.h Manejo_de_archivos.cpp "Estructuras_y_Punteros.cpp" "Estructuras_y_Punteros.h" Manejo_de_archivos.h Validaciones.cpp Validaciones.h Constantes.h)
