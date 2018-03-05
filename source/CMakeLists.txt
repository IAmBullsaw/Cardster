set(src
  window.cpp
)
add_executable(${PROJECT_NAME} main.cpp ${src})
message(STATUS "Found SDL2 library: ${SDL2_LIBRARIES}")
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
