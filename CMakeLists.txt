cmake_minimum_required(VERSION 3.17)
project(psx)

set(CMAKE_CXX_STANDARD 14)

add_executable(psx main.cpp src/cpu/Cpu.cpp src/cpu/Cpu.h)