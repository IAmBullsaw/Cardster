cmake_minimum_required(VERSION 3.9.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++-4.0)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_compile_options(-Wall -Wextra -Wpedantic)
project (Cardster)

# SDL2
#
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# The thing
#
option(BUILD_SOURCE "Build source" ON)
if (BUILD_SOURCE)
  add_subdirectory (source)
endif()

# Unit tests GTest
#
option(BUILD_TESTS "Build tests via GTest" ON)
if (BUILD_TESTS)
  add_subdirectory (tests)
endif()

# Doxygen Documentation
#
option(BUILD_DOC "Build Documentation via Doxygen" ON)
if (BUILD_DOC)
  add_subdirectory (docs)
endif()
