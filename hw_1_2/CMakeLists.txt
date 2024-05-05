cmake_minimum_required(VERSION 3.5)

project(hw_1_2 LANGUAGES CXX)

set(HEADERS sqlselectquerybuilder.h)
set(SOURCES sqlselectquerybuilder.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_1_2 main.cpp ${HEADERS} ${SOURCES})
