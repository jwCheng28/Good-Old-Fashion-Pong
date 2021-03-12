cmake_minimum_required(VERSION 3.0)

project(PongGame)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
)

add_executable(
    PongGame
    ../main.cpp
    ../game.cpp
    ../ball.cpp
    ../paddle.cpp
    ../score.cpp
)

target_link_libraries(
    PongGame
    ${SDL2_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)
