cmake_minimum_required(VERSION 3.5)

project(hw_3_3 LANGUAGES CXX)

set(HEADERS chain.h)
set(SOURCES chain.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_3_3 main.cpp ${HEADERS} ${SOURCES})
