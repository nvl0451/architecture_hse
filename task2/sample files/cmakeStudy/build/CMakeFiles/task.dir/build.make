# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\architecture\task2\sample files\cmakeStudy"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\architecture\task2\sample files\cmakeStudy\build"

# Include any dependencies generated for this target.
include CMakeFiles/task.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task.dir/flags.make

CMakeFiles/task.dir/printHello.cpp.obj: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/printHello.cpp.obj: ../printHello.cpp
CMakeFiles/task.dir/printHello.cpp.obj: CMakeFiles/task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\architecture\task2\sample files\cmakeStudy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task.dir/printHello.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task.dir/printHello.cpp.obj -MF CMakeFiles\task.dir\printHello.cpp.obj.d -o CMakeFiles\task.dir\printHello.cpp.obj -c "C:\architecture\task2\sample files\cmakeStudy\printHello.cpp"

CMakeFiles/task.dir/printHello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/printHello.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\architecture\task2\sample files\cmakeStudy\printHello.cpp" > CMakeFiles\task.dir\printHello.cpp.i

CMakeFiles/task.dir/printHello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/printHello.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\architecture\task2\sample files\cmakeStudy\printHello.cpp" -o CMakeFiles\task.dir\printHello.cpp.s

CMakeFiles/task.dir/main.cpp.obj: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/main.cpp.obj: ../main.cpp
CMakeFiles/task.dir/main.cpp.obj: CMakeFiles/task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\architecture\task2\sample files\cmakeStudy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task.dir/main.cpp.obj -MF CMakeFiles\task.dir\main.cpp.obj.d -o CMakeFiles\task.dir\main.cpp.obj -c "C:\architecture\task2\sample files\cmakeStudy\main.cpp"

CMakeFiles/task.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\architecture\task2\sample files\cmakeStudy\main.cpp" > CMakeFiles\task.dir\main.cpp.i

CMakeFiles/task.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\architecture\task2\sample files\cmakeStudy\main.cpp" -o CMakeFiles\task.dir\main.cpp.s

# Object files for target task
task_OBJECTS = \
"CMakeFiles/task.dir/printHello.cpp.obj" \
"CMakeFiles/task.dir/main.cpp.obj"

# External object files for target task
task_EXTERNAL_OBJECTS =

../bin/task.exe: CMakeFiles/task.dir/printHello.cpp.obj
../bin/task.exe: CMakeFiles/task.dir/main.cpp.obj
../bin/task.exe: CMakeFiles/task.dir/build.make
../bin/task.exe: CMakeFiles/task.dir/linklibs.rsp
../bin/task.exe: CMakeFiles/task.dir/objects1.rsp
../bin/task.exe: CMakeFiles/task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\architecture\task2\sample files\cmakeStudy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\task.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\task.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task.dir/build: ../bin/task.exe
.PHONY : CMakeFiles/task.dir/build

CMakeFiles/task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task.dir\cmake_clean.cmake
.PHONY : CMakeFiles/task.dir/clean

CMakeFiles/task.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\architecture\task2\sample files\cmakeStudy" "C:\architecture\task2\sample files\cmakeStudy" "C:\architecture\task2\sample files\cmakeStudy\build" "C:\architecture\task2\sample files\cmakeStudy\build" "C:\architecture\task2\sample files\cmakeStudy\build\CMakeFiles\task.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/task.dir/depend

