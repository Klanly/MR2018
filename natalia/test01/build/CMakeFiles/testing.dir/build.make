# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\natas\CLionProjects\Common\natalia\test01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\natas\CLionProjects\Common\natalia\test01\build

# Include any dependencies generated for this target.
include CMakeFiles/testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testing.dir/flags.make

CMakeFiles/testing.dir/main.c.obj: CMakeFiles/testing.dir/flags.make
CMakeFiles/testing.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\natas\CLionProjects\Common\natalia\test01\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testing.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\testing.dir\main.c.obj   -c C:\Users\natas\CLionProjects\Common\natalia\test01\main.c

CMakeFiles/testing.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testing.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\natas\CLionProjects\Common\natalia\test01\main.c > CMakeFiles\testing.dir\main.c.i

CMakeFiles/testing.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testing.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\natas\CLionProjects\Common\natalia\test01\main.c -o CMakeFiles\testing.dir\main.c.s

# Object files for target testing
testing_OBJECTS = \
"CMakeFiles/testing.dir/main.c.obj"

# External object files for target testing
testing_EXTERNAL_OBJECTS =

testing.exe: CMakeFiles/testing.dir/main.c.obj
testing.exe: CMakeFiles/testing.dir/build.make
testing.exe: libnatalialib.a
testing.exe: CMakeFiles/testing.dir/linklibs.rsp
testing.exe: CMakeFiles/testing.dir/objects1.rsp
testing.exe: CMakeFiles/testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\natas\CLionProjects\Common\natalia\test01\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable testing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testing.dir/build: testing.exe

.PHONY : CMakeFiles/testing.dir/build

CMakeFiles/testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testing.dir/clean

CMakeFiles/testing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\natas\CLionProjects\Common\natalia\test01 C:\Users\natas\CLionProjects\Common\natalia\test01 C:\Users\natas\CLionProjects\Common\natalia\test01\build C:\Users\natas\CLionProjects\Common\natalia\test01\build C:\Users\natas\CLionProjects\Common\natalia\test01\build\CMakeFiles\testing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testing.dir/depend

