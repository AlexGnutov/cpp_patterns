cmake_minimum_required(VERSION 3.5)

project(hw_3_1 LANGUAGES CXX)

set(HEADERS command.h)
set(SOURCES command.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_3_1 main.cpp ${HEADERS} ${SOURCES})
