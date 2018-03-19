set(src
  window.cpp
)
add_executable(${PROJECT_NAME} main.cpp ${src})
message(STATUS "Found SDL2 library: ${SDL2_LIBRARIES}")

# This strip is done since the variable contains a
# trailing whitespace by default for some idiotic reason
#
string(STRIP ${SDL2_LIBRARIES} SDL2_stripped)
target_link_libraries(${PROJECT_NAME} ${SDL2_stripped})

if (BUILD_TESTS)
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if (COVERAGE)
  target_compile_options(${PROJECT_NAME} PRIVATE -fprofile-instr-generate -fcoverage-mapping -g -O0)
  target_link_libraries(${PROJECT_NAME} -fprofile-instr-generate -fcoverage-mapping -g -O0)
endif()
