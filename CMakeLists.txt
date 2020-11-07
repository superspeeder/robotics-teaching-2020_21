cmake_minimum_required(VERSION 3.18)
project(RoboticsCXX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Main src/Main.cpp)

target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/include/)

add_custom_target(Run COMMAND Main)