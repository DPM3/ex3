project(Ex1)
cmake_minimum_required(VERSION 3.0.0)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

#compile libmatrix.so
add_library(errorCode SHARED ErrorCode.c)
add_library(matrix SHARED Matrix.c)
add_library(errorExcept SHARED ErrorCodeException.cpp)
add_library(matrixClass SHARED MatrixClass.cpp)

target_link_libraries(matrix errorCode)
target_link_libraries(matrixClass matrix errorExcept)
