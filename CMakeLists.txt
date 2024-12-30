cmake_minimum_required(VERSION 3.10)

project(artApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(artApp src/main.cpp src/colorButton.cpp src/brush.cpp src/canvas.cpp)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(artApp sfml-graphics sfml-window sfml-system)