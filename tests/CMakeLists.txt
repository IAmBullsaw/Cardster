set(GTest_version 1.8.0)
set(GTest_url "https://github.com/google/googletest/archive/release-${GTest_version}.zip")
set(GTest_md5 "4577b49f2973c90bf9ba69aa8166b786")
set(GTest_BUILD_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/build")
set(GTest_BUILD_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install")
set(GTest_DOWNLOAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../downloads")

include(ExternalProject)
ExternalProject_Add(GTest
  URL ${GTest_url}
  PREFIX  ${GTest_BUILD_PREFIX}
  DOWNLOAD_DIR ${GTest_DOWNLOAD_DIR}
  CMAKE_GENERATOR ${gen}
  CMAKE_ARGS
    -DBUILD_SHARED_LIBS:BOOL=ON
    -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX:PATH=${GTest_BUILD_INSTALL_PREFIX}
    -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
)
set(GTEST_ROOT ${GTest_BUILD_INSTALL_PREFIX} CACHE STRING "")
message(STATUS "GTEST_ROOT = ${GTEST_ROOT}")

find_package(GTest)
if (GTEST_FOUND)
  enable_testing()
  include_directories(${GTEST_INCLUDE_DIRS})

  add_executable(tests main.cpp)
  target_link_libraries(tests ${GTEST_BOTH_LIBRARIES})
  add_test(NAME AllTestsInMain COMMAND tests)

else (GTEST_FOUND)
  message(WARNING "Gtest not found.\nRun make to install GTest.\nRerun cmake to finish test install.")
endif()
