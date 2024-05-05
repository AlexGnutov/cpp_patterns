cmake_minimum_required(VERSION 3.5)

project(hw_2_2 LANGUAGES CXX)

set(HEADERS proxy.h)
set(SOURCES proxy.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_2_2 main.cpp ${HEADERS} ${SOURCES})
