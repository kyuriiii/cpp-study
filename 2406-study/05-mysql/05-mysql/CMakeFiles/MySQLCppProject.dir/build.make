# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql

# Include any dependencies generated for this target.
include CMakeFiles/MySQLCppProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MySQLCppProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MySQLCppProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MySQLCppProject.dir/flags.make

CMakeFiles/MySQLCppProject.dir/main.cpp.o: CMakeFiles/MySQLCppProject.dir/flags.make
CMakeFiles/MySQLCppProject.dir/main.cpp.o: main.cpp
CMakeFiles/MySQLCppProject.dir/main.cpp.o: CMakeFiles/MySQLCppProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySQLCppProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MySQLCppProject.dir/main.cpp.o -MF CMakeFiles/MySQLCppProject.dir/main.cpp.o.d -o CMakeFiles/MySQLCppProject.dir/main.cpp.o -c /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/main.cpp

CMakeFiles/MySQLCppProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MySQLCppProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/main.cpp > CMakeFiles/MySQLCppProject.dir/main.cpp.i

CMakeFiles/MySQLCppProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MySQLCppProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/main.cpp -o CMakeFiles/MySQLCppProject.dir/main.cpp.s

# Object files for target MySQLCppProject
MySQLCppProject_OBJECTS = \
"CMakeFiles/MySQLCppProject.dir/main.cpp.o"

# External object files for target MySQLCppProject
MySQLCppProject_EXTERNAL_OBJECTS =

MySQLCppProject: CMakeFiles/MySQLCppProject.dir/main.cpp.o
MySQLCppProject: CMakeFiles/MySQLCppProject.dir/build.make
MySQLCppProject: CMakeFiles/MySQLCppProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MySQLCppProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MySQLCppProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MySQLCppProject.dir/build: MySQLCppProject
.PHONY : CMakeFiles/MySQLCppProject.dir/build

CMakeFiles/MySQLCppProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MySQLCppProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MySQLCppProject.dir/clean

CMakeFiles/MySQLCppProject.dir/depend:
	cd /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql /Users/kyuri/Desktop/Github/cpp/cpp-study/2406-study/05-mysql/05-mysql/CMakeFiles/MySQLCppProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MySQLCppProject.dir/depend

