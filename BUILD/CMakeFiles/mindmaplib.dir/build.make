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
include CMakeFiles/mindmaplib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mindmaplib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mindmaplib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mindmaplib.dir/flags.make

CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj: ../libgraphics/exceptio.c
CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj -c D:/GitHub/MindMap/libgraphics/exceptio.c

CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/exceptio.c > CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.i

CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/exceptio.c -o CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.s

CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj: ../libgraphics/genlib.c
CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj -c D:/GitHub/MindMap/libgraphics/genlib.c

CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/genlib.c > CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.i

CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/genlib.c -o CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.s

CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj: ../libgraphics/graphics.c
CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj -c D:/GitHub/MindMap/libgraphics/graphics.c

CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/graphics.c > CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.i

CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/graphics.c -o CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.s

CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj: ../libgraphics/linkedlist.c
CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj -c D:/GitHub/MindMap/libgraphics/linkedlist.c

CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/linkedlist.c > CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.i

CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/linkedlist.c -o CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.s

CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj: ../libgraphics/random.c
CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj -c D:/GitHub/MindMap/libgraphics/random.c

CMakeFiles/mindmaplib.dir/libgraphics/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/random.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/random.c > CMakeFiles/mindmaplib.dir/libgraphics/random.c.i

CMakeFiles/mindmaplib.dir/libgraphics/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/random.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/random.c -o CMakeFiles/mindmaplib.dir/libgraphics/random.c.s

CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj: ../libgraphics/simpio.c
CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj -c D:/GitHub/MindMap/libgraphics/simpio.c

CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/simpio.c > CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.i

CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/simpio.c -o CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.s

CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj: ../libgraphics/strlib.c
CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj -MF CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj.d -o CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj -c D:/GitHub/MindMap/libgraphics/strlib.c

CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/libgraphics/strlib.c > CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.i

CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/libgraphics/strlib.c -o CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.s

CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj: ../simpleGUI/imgui.c
CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj -MF CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj.d -o CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj -c D:/GitHub/MindMap/simpleGUI/imgui.c

CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/simpleGUI/imgui.c > CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.i

CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/simpleGUI/imgui.c -o CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.s

CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj: ../mindmap/ButtonRelated.c
CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj -MF CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj.d -o CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj -c D:/GitHub/MindMap/mindmap/ButtonRelated.c

CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/mindmap/ButtonRelated.c > CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.i

CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/mindmap/ButtonRelated.c -o CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.s

CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj: ../mindmap/Line.c
CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj -MF CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj.d -o CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj -c D:/GitHub/MindMap/mindmap/Line.c

CMakeFiles/mindmaplib.dir/mindmap/Line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/mindmap/Line.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/mindmap/Line.c > CMakeFiles/mindmaplib.dir/mindmap/Line.c.i

CMakeFiles/mindmaplib.dir/mindmap/Line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/mindmap/Line.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/mindmap/Line.c -o CMakeFiles/mindmaplib.dir/mindmap/Line.c.s

CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj: ../mindmap/TextBox.c
CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj -MF CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj.d -o CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj -c D:/GitHub/MindMap/mindmap/TextBox.c

CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/mindmap/TextBox.c > CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.i

CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/mindmap/TextBox.c -o CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.s

CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj: CMakeFiles/mindmaplib.dir/flags.make
CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj: CMakeFiles/mindmaplib.dir/includes_C.rsp
CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj: ../mindmap/Display.c
CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj: CMakeFiles/mindmaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj -MF CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj.d -o CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj -c D:/GitHub/MindMap/mindmap/Display.c

CMakeFiles/mindmaplib.dir/mindmap/Display.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mindmaplib.dir/mindmap/Display.c.i"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/GitHub/MindMap/mindmap/Display.c > CMakeFiles/mindmaplib.dir/mindmap/Display.c.i

CMakeFiles/mindmaplib.dir/mindmap/Display.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mindmaplib.dir/mindmap/Display.c.s"
	D:/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/GitHub/MindMap/mindmap/Display.c -o CMakeFiles/mindmaplib.dir/mindmap/Display.c.s

# Object files for target mindmaplib
mindmaplib_OBJECTS = \
"CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj" \
"CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj" \
"CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj" \
"CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj" \
"CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj" \
"CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj" \
"CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj"

# External object files for target mindmaplib
mindmaplib_EXTERNAL_OBJECTS =

libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/exceptio.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/genlib.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/graphics.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/linkedlist.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/random.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/simpio.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/libgraphics/strlib.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/simpleGUI/imgui.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/mindmap/ButtonRelated.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/mindmap/Line.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/mindmap/TextBox.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/mindmap/Display.c.obj
libmindmaplib.a: CMakeFiles/mindmaplib.dir/build.make
libmindmaplib.a: CMakeFiles/mindmaplib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/GitHub/MindMap/BUILD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C static library libmindmaplib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mindmaplib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mindmaplib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mindmaplib.dir/build: libmindmaplib.a
.PHONY : CMakeFiles/mindmaplib.dir/build

CMakeFiles/mindmaplib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mindmaplib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mindmaplib.dir/clean

CMakeFiles/mindmaplib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/GitHub/MindMap D:/GitHub/MindMap D:/GitHub/MindMap/BUILD D:/GitHub/MindMap/BUILD D:/GitHub/MindMap/BUILD/CMakeFiles/mindmaplib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mindmaplib.dir/depend

