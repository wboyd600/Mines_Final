# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/wesley/Downloads/clion-2018.2.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wesley/Downloads/clion-2018.2.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wesley/CLionProjects/Mines_Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wesley/CLionProjects/Mines_Final/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OKAY.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OKAY.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OKAY.dir/flags.make

CMakeFiles/OKAY.dir/src/main.cpp.o: CMakeFiles/OKAY.dir/flags.make
CMakeFiles/OKAY.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wesley/CLionProjects/Mines_Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OKAY.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OKAY.dir/src/main.cpp.o -c /home/wesley/CLionProjects/Mines_Final/src/main.cpp

CMakeFiles/OKAY.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OKAY.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wesley/CLionProjects/Mines_Final/src/main.cpp > CMakeFiles/OKAY.dir/src/main.cpp.i

CMakeFiles/OKAY.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OKAY.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wesley/CLionProjects/Mines_Final/src/main.cpp -o CMakeFiles/OKAY.dir/src/main.cpp.s

# Object files for target OKAY
OKAY_OBJECTS = \
"CMakeFiles/OKAY.dir/src/main.cpp.o"

# External object files for target OKAY
OKAY_EXTERNAL_OBJECTS =

OKAY: CMakeFiles/OKAY.dir/src/main.cpp.o
OKAY: CMakeFiles/OKAY.dir/build.make
OKAY: /usr/lib/x86_64-linux-gnu/libsfml-system.so
OKAY: /usr/lib/x86_64-linux-gnu/libsfml-window.so
OKAY: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
OKAY: /usr/lib/x86_64-linux-gnu/libsfml-network.so
OKAY: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
OKAY: CMakeFiles/OKAY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wesley/CLionProjects/Mines_Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OKAY"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OKAY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OKAY.dir/build: OKAY

.PHONY : CMakeFiles/OKAY.dir/build

CMakeFiles/OKAY.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OKAY.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OKAY.dir/clean

CMakeFiles/OKAY.dir/depend:
	cd /home/wesley/CLionProjects/Mines_Final/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wesley/CLionProjects/Mines_Final /home/wesley/CLionProjects/Mines_Final /home/wesley/CLionProjects/Mines_Final/cmake-build-debug /home/wesley/CLionProjects/Mines_Final/cmake-build-debug /home/wesley/CLionProjects/Mines_Final/cmake-build-debug/CMakeFiles/OKAY.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OKAY.dir/depend

