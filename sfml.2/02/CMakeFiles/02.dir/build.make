# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\system\CppDistro\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\system\CppDistro\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\study\ispring\projectPractice\sfml.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\study\ispring\projectPractice\sfml.2

# Include any dependencies generated for this target.
include 02/CMakeFiles/02.dir/depend.make

# Include the progress variables for this target.
include 02/CMakeFiles/02.dir/progress.make

# Include the compile flags for this target's objects.
include 02/CMakeFiles/02.dir/flags.make

02/CMakeFiles/02.dir/main.cpp.obj: 02/CMakeFiles/02.dir/flags.make
02/CMakeFiles/02.dir/main.cpp.obj: 02/CMakeFiles/02.dir/includes_CXX.rsp
02/CMakeFiles/02.dir/main.cpp.obj: 02/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\study\ispring\projectPractice\sfml.2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 02/CMakeFiles/02.dir/main.cpp.obj"
	cd /d C:\study\ispring\projectPractice\sfml.2\02 && C:\system\CppDistro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\02.dir\main.cpp.obj -c C:\study\ispring\projectPractice\sfml.2\02\main.cpp

02/CMakeFiles/02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/02.dir/main.cpp.i"
	cd /d C:\study\ispring\projectPractice\sfml.2\02 && C:\system\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\study\ispring\projectPractice\sfml.2\02\main.cpp > CMakeFiles\02.dir\main.cpp.i

02/CMakeFiles/02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/02.dir/main.cpp.s"
	cd /d C:\study\ispring\projectPractice\sfml.2\02 && C:\system\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\study\ispring\projectPractice\sfml.2\02\main.cpp -o CMakeFiles\02.dir\main.cpp.s

02/CMakeFiles/02.dir/main.cpp.obj.requires:

.PHONY : 02/CMakeFiles/02.dir/main.cpp.obj.requires

02/CMakeFiles/02.dir/main.cpp.obj.provides: 02/CMakeFiles/02.dir/main.cpp.obj.requires
	$(MAKE) -f 02\CMakeFiles\02.dir\build.make 02/CMakeFiles/02.dir/main.cpp.obj.provides.build
.PHONY : 02/CMakeFiles/02.dir/main.cpp.obj.provides

02/CMakeFiles/02.dir/main.cpp.obj.provides.build: 02/CMakeFiles/02.dir/main.cpp.obj


# Object files for target 02
02_OBJECTS = \
"CMakeFiles/02.dir/main.cpp.obj"

# External object files for target 02
02_EXTERNAL_OBJECTS =

02/02.exe: 02/CMakeFiles/02.dir/main.cpp.obj
02/02.exe: 02/CMakeFiles/02.dir/build.make
02/02.exe: C:/system/CppDistro/MinGW/lib/libsfml-window-s.a
02/02.exe: C:/system/CppDistro/MinGW/lib/libsfml-graphics-s.a
02/02.exe: C:/system/CppDistro/MinGW/lib/libsfml-system-s.a
02/02.exe: C:/system/CppDistro/MinGW/lib/libfreetype.a
02/02.exe: C:/system/CppDistro/MinGW/lib/libjpeg.a
02/02.exe: 02/CMakeFiles/02.dir/linklibs.rsp
02/02.exe: 02/CMakeFiles/02.dir/objects1.rsp
02/02.exe: 02/CMakeFiles/02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\study\ispring\projectPractice\sfml.2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 02.exe"
	cd /d C:\study\ispring\projectPractice\sfml.2\02 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
02/CMakeFiles/02.dir/build: 02/02.exe

.PHONY : 02/CMakeFiles/02.dir/build

02/CMakeFiles/02.dir/requires: 02/CMakeFiles/02.dir/main.cpp.obj.requires

.PHONY : 02/CMakeFiles/02.dir/requires

02/CMakeFiles/02.dir/clean:
	cd /d C:\study\ispring\projectPractice\sfml.2\02 && $(CMAKE_COMMAND) -P CMakeFiles\02.dir\cmake_clean.cmake
.PHONY : 02/CMakeFiles/02.dir/clean

02/CMakeFiles/02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\study\ispring\projectPractice\sfml.2 C:\study\ispring\projectPractice\sfml.2\02 C:\study\ispring\projectPractice\sfml.2 C:\study\ispring\projectPractice\sfml.2\02 C:\study\ispring\projectPractice\sfml.2\02\CMakeFiles\02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 02/CMakeFiles/02.dir/depend

