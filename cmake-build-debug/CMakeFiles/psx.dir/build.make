# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/breno/CLionProjects/psx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/breno/CLionProjects/psx/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/psx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/psx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/psx.dir/flags.make

CMakeFiles/psx.dir/main.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/psx.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/main.cpp.o -c /home/breno/CLionProjects/psx/main.cpp

CMakeFiles/psx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/main.cpp > CMakeFiles/psx.dir/main.cpp.i

CMakeFiles/psx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/main.cpp -o CMakeFiles/psx.dir/main.cpp.s

CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o: ../src/cpu/Cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o -c /home/breno/CLionProjects/psx/src/cpu/Cpu.cpp

CMakeFiles/psx.dir/src/cpu/Cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/cpu/Cpu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/cpu/Cpu.cpp > CMakeFiles/psx.dir/src/cpu/Cpu.cpp.i

CMakeFiles/psx.dir/src/cpu/Cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/cpu/Cpu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/cpu/Cpu.cpp -o CMakeFiles/psx.dir/src/cpu/Cpu.cpp.s

CMakeFiles/psx.dir/src/bios/Bios.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/bios/Bios.cpp.o: ../src/bios/Bios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/psx.dir/src/bios/Bios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/bios/Bios.cpp.o -c /home/breno/CLionProjects/psx/src/bios/Bios.cpp

CMakeFiles/psx.dir/src/bios/Bios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/bios/Bios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/bios/Bios.cpp > CMakeFiles/psx.dir/src/bios/Bios.cpp.i

CMakeFiles/psx.dir/src/bios/Bios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/bios/Bios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/bios/Bios.cpp -o CMakeFiles/psx.dir/src/bios/Bios.cpp.s

CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o: ../src/interconnect/Interconnect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o -c /home/breno/CLionProjects/psx/src/interconnect/Interconnect.cpp

CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/interconnect/Interconnect.cpp > CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.i

CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/interconnect/Interconnect.cpp -o CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.s

CMakeFiles/psx.dir/src/range/Range.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/range/Range.cpp.o: ../src/range/Range.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/psx.dir/src/range/Range.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/range/Range.cpp.o -c /home/breno/CLionProjects/psx/src/range/Range.cpp

CMakeFiles/psx.dir/src/range/Range.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/range/Range.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/range/Range.cpp > CMakeFiles/psx.dir/src/range/Range.cpp.i

CMakeFiles/psx.dir/src/range/Range.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/range/Range.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/range/Range.cpp -o CMakeFiles/psx.dir/src/range/Range.cpp.s

CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o: ../src/cpu/Instruction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o -c /home/breno/CLionProjects/psx/src/cpu/Instruction.cpp

CMakeFiles/psx.dir/src/cpu/Instruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/cpu/Instruction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/cpu/Instruction.cpp > CMakeFiles/psx.dir/src/cpu/Instruction.cpp.i

CMakeFiles/psx.dir/src/cpu/Instruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/cpu/Instruction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/cpu/Instruction.cpp -o CMakeFiles/psx.dir/src/cpu/Instruction.cpp.s

CMakeFiles/psx.dir/src/utils/utils.cpp.o: CMakeFiles/psx.dir/flags.make
CMakeFiles/psx.dir/src/utils/utils.cpp.o: ../src/utils/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/psx.dir/src/utils/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/psx.dir/src/utils/utils.cpp.o -c /home/breno/CLionProjects/psx/src/utils/utils.cpp

CMakeFiles/psx.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/psx.dir/src/utils/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breno/CLionProjects/psx/src/utils/utils.cpp > CMakeFiles/psx.dir/src/utils/utils.cpp.i

CMakeFiles/psx.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/psx.dir/src/utils/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breno/CLionProjects/psx/src/utils/utils.cpp -o CMakeFiles/psx.dir/src/utils/utils.cpp.s

# Object files for target psx
psx_OBJECTS = \
"CMakeFiles/psx.dir/main.cpp.o" \
"CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o" \
"CMakeFiles/psx.dir/src/bios/Bios.cpp.o" \
"CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o" \
"CMakeFiles/psx.dir/src/range/Range.cpp.o" \
"CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o" \
"CMakeFiles/psx.dir/src/utils/utils.cpp.o"

# External object files for target psx
psx_EXTERNAL_OBJECTS =

psx: CMakeFiles/psx.dir/main.cpp.o
psx: CMakeFiles/psx.dir/src/cpu/Cpu.cpp.o
psx: CMakeFiles/psx.dir/src/bios/Bios.cpp.o
psx: CMakeFiles/psx.dir/src/interconnect/Interconnect.cpp.o
psx: CMakeFiles/psx.dir/src/range/Range.cpp.o
psx: CMakeFiles/psx.dir/src/cpu/Instruction.cpp.o
psx: CMakeFiles/psx.dir/src/utils/utils.cpp.o
psx: CMakeFiles/psx.dir/build.make
psx: CMakeFiles/psx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable psx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/psx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/psx.dir/build: psx

.PHONY : CMakeFiles/psx.dir/build

CMakeFiles/psx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/psx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/psx.dir/clean

CMakeFiles/psx.dir/depend:
	cd /home/breno/CLionProjects/psx/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/breno/CLionProjects/psx /home/breno/CLionProjects/psx /home/breno/CLionProjects/psx/cmake-build-debug /home/breno/CLionProjects/psx/cmake-build-debug /home/breno/CLionProjects/psx/cmake-build-debug/CMakeFiles/psx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/psx.dir/depend

