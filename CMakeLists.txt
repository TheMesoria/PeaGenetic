cmake_minimum_required(VERSION 3.9)
project(PEAGenetic)

set(CMAKE_CXX_STANDARD 17)

add_executable(PEAGenetic
        src/main.cpp
        src/FileLoader/FileLoader.cpp
        src/FileLoader/FileLoader.hpp
        )