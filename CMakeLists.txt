cmake_minimum_required(VERSION 3.21)
project(El_eterno_dilema_del_lector)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wconversion -Werror" )

add_executable(El_eterno_dilema_del_lector main.cpp util.cpp util.h)
