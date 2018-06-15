cmake_minimum_required(VERSION 3.10)
project(dots)

set(CMAKE_CXX_STANDARD 11)

add_executable(dots main.cpp mhelpers.cpp mhelpers.h structs.h algo.cpp algo.h iohelpers.cpp iohelpers.h)