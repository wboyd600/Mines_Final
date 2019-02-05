cmake_minimum_required(VERSION 3.3)
set(EXECUTABLE_NAME "Mines_Final")
add_executable(${EXECUTABLE_NAME} src/main.cpp src/Board.cpp)



# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()