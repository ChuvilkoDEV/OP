# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programms\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programms\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/13__Vanya_and_blocks.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/13__Vanya_and_blocks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/13__Vanya_and_blocks.dir/flags.make

CMakeFiles/13__Vanya_and_blocks.dir/main.c.obj: CMakeFiles/13__Vanya_and_blocks.dir/flags.make
CMakeFiles/13__Vanya_and_blocks.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/13__Vanya_and_blocks.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\13__Vanya_and_blocks.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\main.c"

CMakeFiles/13__Vanya_and_blocks.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/13__Vanya_and_blocks.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\main.c" > CMakeFiles\13__Vanya_and_blocks.dir\main.c.i

CMakeFiles/13__Vanya_and_blocks.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/13__Vanya_and_blocks.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\main.c" -o CMakeFiles\13__Vanya_and_blocks.dir\main.c.s

# Object files for target 13__Vanya_and_blocks
13__Vanya_and_blocks_OBJECTS = \
"CMakeFiles/13__Vanya_and_blocks.dir/main.c.obj"

# External object files for target 13__Vanya_and_blocks
13__Vanya_and_blocks_EXTERNAL_OBJECTS =

13__Vanya_and_blocks.exe: CMakeFiles/13__Vanya_and_blocks.dir/main.c.obj
13__Vanya_and_blocks.exe: CMakeFiles/13__Vanya_and_blocks.dir/build.make
13__Vanya_and_blocks.exe: CMakeFiles/13__Vanya_and_blocks.dir/linklibs.rsp
13__Vanya_and_blocks.exe: CMakeFiles/13__Vanya_and_blocks.dir/objects1.rsp
13__Vanya_and_blocks.exe: CMakeFiles/13__Vanya_and_blocks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 13__Vanya_and_blocks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\13__Vanya_and_blocks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/13__Vanya_and_blocks.dir/build: 13__Vanya_and_blocks.exe
.PHONY : CMakeFiles/13__Vanya_and_blocks.dir/build

CMakeFiles/13__Vanya_and_blocks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\13__Vanya_and_blocks.dir\cmake_clean.cmake
.PHONY : CMakeFiles/13__Vanya_and_blocks.dir/clean

CMakeFiles/13__Vanya_and_blocks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks" "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks" "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\13. Vanya and blocks\cmake-build-debug\CMakeFiles\13__Vanya_and_blocks.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/13__Vanya_and_blocks.dir/depend

