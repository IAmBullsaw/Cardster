cmake_minimum_required(VERSION 3.9.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++-4.0)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project (Cardster)

# SDL2
#
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# The options
#
option(BUILD_SOURCE "Build source" ON)
option(BUILD_DOC "Build Documentation via Doxygen" ON)
option(COVERAGE "Make code coverage available" OFF)
option(BUILD_TESTS "Build tests via GTest" OFF)

# The thing
#
if (BUILD_SOURCE)
  add_subdirectory (src)
endif()

# Unit tests GTest
#
if (BUILD_TESTS)
  add_subdirectory (tests)
endif()

# Doxygen Documentation
#
if (BUILD_DOC)
  add_subdirectory (docs)
endif()
