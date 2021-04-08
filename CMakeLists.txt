cmake_minimum_required(VERSION 3.17)
project(psx)

set(CMAKE_CXX_STANDARD 14)

add_executable(psx main.cpp src/cpu/Cpu.cpp src/cpu/Cpu.h src/bios/Bios.cpp src/bios/Bios.h src/interconnect/Interconnect.cpp src/interconnect/Interconnect.h src/range/Range.cpp src/range/Range.h src/cpu/Instruction.cpp src/cpu/Instruction.h)