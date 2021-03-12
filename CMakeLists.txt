cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11")

project(PongGame)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(
    PongGame
    main.cpp
    game.cpp
    ball.cpp
    paddle.cpp
    score.cpp
    ${SDL2_LIBRARY}
)

