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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\6e\queue\2. Photo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/2__Photo.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/2__Photo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2__Photo.dir/flags.make

CMakeFiles/2__Photo.dir/main.cpp.obj: CMakeFiles/2__Photo.dir/flags.make
CMakeFiles/2__Photo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2__Photo.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2__Photo.dir\main.cpp.obj -c "D:\BGTU\Programming Basics\6e\queue\2. Photo\main.cpp"

CMakeFiles/2__Photo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2__Photo.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\BGTU\Programming Basics\6e\queue\2. Photo\main.cpp" > CMakeFiles\2__Photo.dir\main.cpp.i

CMakeFiles/2__Photo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2__Photo.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\BGTU\Programming Basics\6e\queue\2. Photo\main.cpp" -o CMakeFiles\2__Photo.dir\main.cpp.s

# Object files for target 2__Photo
2__Photo_OBJECTS = \
"CMakeFiles/2__Photo.dir/main.cpp.obj"

# External object files for target 2__Photo
2__Photo_EXTERNAL_OBJECTS =

2__Photo.exe: CMakeFiles/2__Photo.dir/main.cpp.obj
2__Photo.exe: CMakeFiles/2__Photo.dir/build.make
2__Photo.exe: CMakeFiles/2__Photo.dir/linklibs.rsp
2__Photo.exe: CMakeFiles/2__Photo.dir/objects1.rsp
2__Photo.exe: CMakeFiles/2__Photo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2__Photo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2__Photo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2__Photo.dir/build: 2__Photo.exe
.PHONY : CMakeFiles/2__Photo.dir/build

CMakeFiles/2__Photo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2__Photo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2__Photo.dir/clean

CMakeFiles/2__Photo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\6e\queue\2. Photo" "D:\BGTU\Programming Basics\6e\queue\2. Photo" "D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug" "D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug" "D:\BGTU\Programming Basics\6e\queue\2. Photo\cmake-build-debug\CMakeFiles\2__Photo.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/2__Photo.dir/depend

