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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/12__opens_for_friends.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/12__opens_for_friends.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12__opens_for_friends.dir/flags.make

CMakeFiles/12__opens_for_friends.dir/main.c.obj: CMakeFiles/12__opens_for_friends.dir/flags.make
CMakeFiles/12__opens_for_friends.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/12__opens_for_friends.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\12__opens_for_friends.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\main.c"

CMakeFiles/12__opens_for_friends.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/12__opens_for_friends.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\main.c" > CMakeFiles\12__opens_for_friends.dir\main.c.i

CMakeFiles/12__opens_for_friends.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/12__opens_for_friends.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\main.c" -o CMakeFiles\12__opens_for_friends.dir\main.c.s

# Object files for target 12__opens_for_friends
12__opens_for_friends_OBJECTS = \
"CMakeFiles/12__opens_for_friends.dir/main.c.obj"

# External object files for target 12__opens_for_friends
12__opens_for_friends_EXTERNAL_OBJECTS =

12__opens_for_friends.exe: CMakeFiles/12__opens_for_friends.dir/main.c.obj
12__opens_for_friends.exe: CMakeFiles/12__opens_for_friends.dir/build.make
12__opens_for_friends.exe: CMakeFiles/12__opens_for_friends.dir/linklibs.rsp
12__opens_for_friends.exe: CMakeFiles/12__opens_for_friends.dir/objects1.rsp
12__opens_for_friends.exe: CMakeFiles/12__opens_for_friends.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 12__opens_for_friends.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12__opens_for_friends.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12__opens_for_friends.dir/build: 12__opens_for_friends.exe
.PHONY : CMakeFiles/12__opens_for_friends.dir/build

CMakeFiles/12__opens_for_friends.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\12__opens_for_friends.dir\cmake_clean.cmake
.PHONY : CMakeFiles/12__opens_for_friends.dir/clean

CMakeFiles/12__opens_for_friends.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends" "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends" "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\12. opens for friends\cmake-build-debug\CMakeFiles\12__opens_for_friends.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/12__opens_for_friends.dir/depend

