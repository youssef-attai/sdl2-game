cmake_minimum_required(VERSION 3.23)
project(2d_game_sdl2)

find_package(SDL2 REQUIRED SDL2)
set(CMAKE_CXX_STANDARD 14)

add_executable(2d_game_sdl2 main.cpp Game.cpp Game.h)
target_link_libraries(2d_game_sdl2 PRIVATE SDL2::SDL2)

