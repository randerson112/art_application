cmake_minimum_required(VERSION 3.10)

project(artApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(artApp src/main.cpp src/colorButton.cpp src/brush.cpp src/canvas.cpp)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

target_link_libraries(artApp SFML::Graphics SFML::Window SFML::System)