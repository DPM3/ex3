project(ex3)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pedantic -Werror)
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_library(cacheManager     SHARED  cacheManager.cpp)
add_library(miniCacheManager SHARED  miniCacheManager.cpp)
add_library(calculator       SHARED  calculator.cpp)
add_library(folderManager    SHARED  folderManager.cpp)
add_library(matrixIO         SHARED  matrixIO.cpp)
add_library(operatorID       SHARED  operatorID.cpp)
add_library(parser           SHARED  parser.cpp)
add_library(sha1             SHARED  sha1.cpp)

add_subdirectory(matrix)
add_subdirectory(bmp_img)

add_executable(main main.cpp)
set_target_properties(main PROPERTIES OUTPUT_NAME "ex3")
set_target_properties(main PROPERTIES SUFFIX ".out")

target_link_libraries(main cacheManager miniCacheManager calculator folderManager matrixIO operatorID parser sha1 matrixClass bmpTester)

link_directories($CMAKE_SOURCE_DIR $CMAKE_SOURCE_DIR/matrix $CMAKE_SOURCE_DIR/bmp_img)

