cmake_minimum_required(VERSION 3.9.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++-4.0)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_compile_options(-Wall -Wextra -Wpedantic)
project (Cardster)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory (source)
