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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/7__I_love_UserName.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/7__I_love_UserName.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/7__I_love_UserName.dir/flags.make

CMakeFiles/7__I_love_UserName.dir/main.c.obj: CMakeFiles/7__I_love_UserName.dir/flags.make
CMakeFiles/7__I_love_UserName.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/7__I_love_UserName.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\7__I_love_UserName.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\main.c"

CMakeFiles/7__I_love_UserName.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7__I_love_UserName.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\main.c" > CMakeFiles\7__I_love_UserName.dir\main.c.i

CMakeFiles/7__I_love_UserName.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7__I_love_UserName.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\main.c" -o CMakeFiles\7__I_love_UserName.dir\main.c.s

# Object files for target 7__I_love_UserName
7__I_love_UserName_OBJECTS = \
"CMakeFiles/7__I_love_UserName.dir/main.c.obj"

# External object files for target 7__I_love_UserName
7__I_love_UserName_EXTERNAL_OBJECTS =

7__I_love_UserName.exe: CMakeFiles/7__I_love_UserName.dir/main.c.obj
7__I_love_UserName.exe: CMakeFiles/7__I_love_UserName.dir/build.make
7__I_love_UserName.exe: CMakeFiles/7__I_love_UserName.dir/linklibs.rsp
7__I_love_UserName.exe: CMakeFiles/7__I_love_UserName.dir/objects1.rsp
7__I_love_UserName.exe: CMakeFiles/7__I_love_UserName.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 7__I_love_UserName.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\7__I_love_UserName.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/7__I_love_UserName.dir/build: 7__I_love_UserName.exe
.PHONY : CMakeFiles/7__I_love_UserName.dir/build

CMakeFiles/7__I_love_UserName.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\7__I_love_UserName.dir\cmake_clean.cmake
.PHONY : CMakeFiles/7__I_love_UserName.dir/clean

CMakeFiles/7__I_love_UserName.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName" "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName" "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3b\7. I love UserName\cmake-build-debug\CMakeFiles\7__I_love_UserName.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/7__I_love_UserName.dir/depend

