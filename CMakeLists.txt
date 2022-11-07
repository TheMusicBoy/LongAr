cmake_minimum_required(VERSION 3.0)

project(big_int)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/big_int.hpp)
set(SOURCES lib/big_int.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})