cmake_minimum_required(VERSION 3.20)
project(AlgoritmosAFondo)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/biblioteca)
include_directories(src/biblioteca/funciones)
include_directories(src/biblioteca/tads)
include_directories(src/biblioteca/tads/huffman)

add_executable(AlgoritmosAFondo_EMPTY_v2_7_3
        src/principal.cpp)
