cmake_minimum_required(VERSION 3.17)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess main.cpp board.cpp pieces.cpp coordinate.cpp)
