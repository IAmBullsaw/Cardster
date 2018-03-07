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
# Unit tests
#
option(BUILD_TESTS "Build tests via GTest" ON)
if (BUILD_TESTS)
  add_subdirectory (tests)
endif()

# Doxygen
#
option(BUILD_DOC "Build Documentation via Doxygen" ON)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  # set input and output files
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  # request to configure the file
  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
  message(STATUS "Doxygen_out ${DOXYGEN_OUT}")

  # note the option ALL which allows to build the docs together with the application
  add_custom_target(docs ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM )
else (DOXYGEN_FOUND)
  if (BUILD_DOC)
    message(FATAL_ERROR "Doxygen is needed to generate the documentation.")
  else (BUILD_DOC)
    message(STATUS "Doxygen is needed to generate the documentation. Document generation is OFF")
  endif()
endif()
