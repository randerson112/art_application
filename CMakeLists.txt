cmake_minimum_required(VERSION 3.10)

project(artProgram)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(artProgram src/main.cpp src/colorButton.cpp)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(artProgram sfml-graphics sfml-window sfml-system)