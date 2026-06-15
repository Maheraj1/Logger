cmake_minimum_required(VERSION 3.10)
project(SLogger VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SLogger STATIC
    src/Log.cpp
    include/Log.hpp
)

target_include_directories(SLogger PUBLIC include)
