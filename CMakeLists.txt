cmake_minimum_required(VERSION 3.13)
project(shipping_render)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/ychixm/Documents/SFML-2.5.1-Compiled/include")
set(SFML_LIBRARY_DIR "/home/ychixm/Documents/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "/home/ychixm/Documents/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(shipping_render main.cpp Place.cpp Place.h Routes.cpp Routes.h)
target_link_libraries (shipping_render sfml-graphics sfml-window sfml-system)