cmake_minimum_required(VERSION 3.12)
project(logic)

include_directories(include)
include_directories(libs/xtl/include)

set(CMAKE_CXX_STANDARD 14)

add_executable(logic main.cpp)

add_subdirectory(test)