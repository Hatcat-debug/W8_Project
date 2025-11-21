cmake_minimum_required(VERSION 4.0)
project(W8_Project)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc")

set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(FidgetLib SHARED FidgetCube.cpp)

add_executable(W8_Main main.cpp)

target_link_libraries(W8_Main FidgetLib)

add_executable(W8_Main2 main2.cpp)

target_link_libraries(W8_Main2 FidgetLib)