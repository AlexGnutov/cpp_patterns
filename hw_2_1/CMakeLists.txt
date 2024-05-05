cmake_minimum_required(VERSION 3.5)

project(hw_2_1 LANGUAGES CXX)

set(HEADERS decorator.h)
set(SOURCES decorator.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_2_1 main.cpp ${HEADERS} ${SOURCES})
