# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = D:/CMake/cmake-3.20.3-windows-x86_64/cmake-3.20.3-windows-x86_64/bin/cmake.exe

# The command to remove a file.
RM = D:/CMake/cmake-3.20.3-windows-x86_64/cmake-3.20.3-windows-x86_64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/GitHub/MindMap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/GitHub/MindMap/BUILD

# Include any dependencies generated for this target.
include CMakeFiles/map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/map.dir/flags.make

CMakeFiles/map.dir/mindmap/Main.c.obj: CMakeFiles/map.dir/flags.make
CMakeFiles/map.dir/mindmap/Main.c.obj: CMakeFiles/map.dir/includes_C.rsp
CMakeFiles/map.dir/mindmap/Main.c.obj: ../mindmap/Main.c
CMakeFiles/map.dir/mindmap/Main.c.obj: CMakeFiles/map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/map.dir/mindmap/Main.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/map.dir/mindmap/Main.c.obj -MF CMakeFiles/map.dir/mindmap/Main.c.obj.d -o CMakeFiles/map.dir/mindmap/Main.c.obj -c D:/GitHub/MindMap/mindmap/Main.c

CMakeFiles/map.dir/mindmap/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/map.dir/mindmap/Main.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/mindmap/Main.c > CMakeFiles/map.dir/mindmap/Main.c.i

CMakeFiles/map.dir/mindmap/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/map.dir/mindmap/Main.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/mindmap/Main.c -o CMakeFiles/map.dir/mindmap/Main.c.s

# Object files for target map
map_OBJECTS = \
"CMakeFiles/map.dir/mindmap/Main.c.obj"

# External object files for target map
map_EXTERNAL_OBJECTS =

map.exe: CMakeFiles/map.dir/mindmap/Main.c.obj
map.exe: CMakeFiles/map.dir/build.make
map.exe: libmindmap.a
map.exe: CMakeFiles/map.dir/linklibs.rsp
map.exe: CMakeFiles/map.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable map.exe"
	D:/CMake/cmake-3.20.3-windows-x86_64/cmake-3.20.3-windows-x86_64/bin/cmake.exe -E rm -f CMakeFiles/map.dir/objects.a
	D:/mingw64/bin/ar.exe cr CMakeFiles/map.dir/objects.a @CMakeFiles/map.dir/objects1.rsp
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe -g -Wl,--whole-archive CMakeFiles/map.dir/objects.a -Wl,--no-whole-archive -o map.exe -Wl,--out-implib,libmap.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/map.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/map.dir/build: map.exe
.PHONY : CMakeFiles/map.dir/build

CMakeFiles/map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/map.dir/clean

CMakeFiles/map.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/GitHub/MindMap D:/GitHub/MindMap D:/GitHub/MindMap/BUILD D:/GitHub/MindMap/BUILD D:/GitHub/MindMap/BUILD/CMakeFiles/map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/map.dir/depend

