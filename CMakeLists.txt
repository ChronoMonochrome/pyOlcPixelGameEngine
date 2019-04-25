cmake_minimum_required(VERSION 2.8.12)
project(olc)

add_subdirectory(pybind11)
pybind11_add_module(olc olc.cpp)