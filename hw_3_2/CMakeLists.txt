cmake_minimum_required(VERSION 3.5)

project(hw_3_2 LANGUAGES CXX)

set(HEADERS observable.h)
set(SOURCES observable.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_3_2 main.cpp ${HEADERS} ${SOURCES})
