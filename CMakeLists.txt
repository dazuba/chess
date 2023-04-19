cmake_minimum_required(VERSION 3.17)
project(chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
find_package(Qt6 REQUIRED COMPONENTS Core Gui SvgWidgets Widgets)
find_package(Drogon CONFIG REQUIRED)
set(CMAKE_AUTOMOC ON)

add_subdirectory(bin)
add_subdirectory(backend)
add_subdirectory(frontend)
add_subdirectory(server)

FILE(COPY media DESTINATION "${CMAKE_BINARY_DIR}")
