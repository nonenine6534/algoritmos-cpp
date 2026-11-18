# CMakeLists.txt — Forma alternativa de compilar el proyecto
# (la otra es el Makefile). Uso:
#
#   cmake -S . -B build     # genera el sistema de compilación
#   cmake --build build     # compila: build/algoritmos y build/pruebas
#   cd build && ctest       # ejecuta las pruebas registradas
#
cmake_minimum_required(VERSION 3.16)
project(algoritmos_cpp CXX)

# Se exige C++17 en todos los ejecutables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Programa principal (menú interactivo). Todo el código vive en
# las cabeceras .h, así que basta compilar main.cpp.
add_executable(algoritmos main.cpp)

# Pruebas automáticas con assert
add_executable(pruebas pruebas.cpp)

# Avisos del compilador también en CMake
if(MSVC)
    target_compile_options(algoritmos PRIVATE /W4)
    target_compile_options(pruebas PRIVATE /W4)
else()
    target_compile_options(algoritmos PRIVATE -Wall -Wextra)
    target_compile_options(pruebas PRIVATE -Wall -Wextra)
endif()

# Registra las pruebas para poder lanzarlas con ctest
enable_testing()
add_test(NAME pruebas COMMAND pruebas)
