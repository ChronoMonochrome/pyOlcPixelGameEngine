cmake_minimum_required(VERSION 2.8.12)
project(olc)

add_subdirectory(pybind11)
pybind11_add_module(olc olc.cpp)

target_include_directories(olc PUBLIC "$(CMAKE_CURRENT_SOURCE_DIR)/olcPixelGameEngine")