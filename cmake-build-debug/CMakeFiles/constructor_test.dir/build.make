# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/constructor_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/constructor_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/constructor_test.dir/flags.make

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o: CMakeFiles/constructor_test.dir/flags.make
CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o: ../test/constructor_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o -c /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/test/constructor_test.cpp

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/constructor_test.dir/test/constructor_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/test/constructor_test.cpp > CMakeFiles/constructor_test.dir/test/constructor_test.cpp.i

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/constructor_test.dir/test/constructor_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/test/constructor_test.cpp -o CMakeFiles/constructor_test.dir/test/constructor_test.cpp.s

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.requires:

.PHONY : CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.requires

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.provides: CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/constructor_test.dir/build.make CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.provides.build
.PHONY : CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.provides

CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.provides.build: CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o


CMakeFiles/constructor_test.dir/src/ll.cpp.o: CMakeFiles/constructor_test.dir/flags.make
CMakeFiles/constructor_test.dir/src/ll.cpp.o: ../src/ll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/constructor_test.dir/src/ll.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/constructor_test.dir/src/ll.cpp.o -c /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/ll.cpp

CMakeFiles/constructor_test.dir/src/ll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/constructor_test.dir/src/ll.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/ll.cpp > CMakeFiles/constructor_test.dir/src/ll.cpp.i

CMakeFiles/constructor_test.dir/src/ll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/constructor_test.dir/src/ll.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/ll.cpp -o CMakeFiles/constructor_test.dir/src/ll.cpp.s

CMakeFiles/constructor_test.dir/src/ll.cpp.o.requires:

.PHONY : CMakeFiles/constructor_test.dir/src/ll.cpp.o.requires

CMakeFiles/constructor_test.dir/src/ll.cpp.o.provides: CMakeFiles/constructor_test.dir/src/ll.cpp.o.requires
	$(MAKE) -f CMakeFiles/constructor_test.dir/build.make CMakeFiles/constructor_test.dir/src/ll.cpp.o.provides.build
.PHONY : CMakeFiles/constructor_test.dir/src/ll.cpp.o.provides

CMakeFiles/constructor_test.dir/src/ll.cpp.o.provides.build: CMakeFiles/constructor_test.dir/src/ll.cpp.o


CMakeFiles/constructor_test.dir/src/snakebody.cpp.o: CMakeFiles/constructor_test.dir/flags.make
CMakeFiles/constructor_test.dir/src/snakebody.cpp.o: ../src/snakebody.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/constructor_test.dir/src/snakebody.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/constructor_test.dir/src/snakebody.cpp.o -c /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/snakebody.cpp

CMakeFiles/constructor_test.dir/src/snakebody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/constructor_test.dir/src/snakebody.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/snakebody.cpp > CMakeFiles/constructor_test.dir/src/snakebody.cpp.i

CMakeFiles/constructor_test.dir/src/snakebody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/constructor_test.dir/src/snakebody.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/src/snakebody.cpp -o CMakeFiles/constructor_test.dir/src/snakebody.cpp.s

CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.requires:

.PHONY : CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.requires

CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.provides: CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.requires
	$(MAKE) -f CMakeFiles/constructor_test.dir/build.make CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.provides.build
.PHONY : CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.provides

CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.provides.build: CMakeFiles/constructor_test.dir/src/snakebody.cpp.o


# Object files for target constructor_test
constructor_test_OBJECTS = \
"CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o" \
"CMakeFiles/constructor_test.dir/src/ll.cpp.o" \
"CMakeFiles/constructor_test.dir/src/snakebody.cpp.o"

# External object files for target constructor_test
constructor_test_EXTERNAL_OBJECTS =

constructor_test: CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o
constructor_test: CMakeFiles/constructor_test.dir/src/ll.cpp.o
constructor_test: CMakeFiles/constructor_test.dir/src/snakebody.cpp.o
constructor_test: CMakeFiles/constructor_test.dir/build.make
constructor_test: CMakeFiles/constructor_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable constructor_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/constructor_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/constructor_test.dir/build: constructor_test

.PHONY : CMakeFiles/constructor_test.dir/build

CMakeFiles/constructor_test.dir/requires: CMakeFiles/constructor_test.dir/test/constructor_test.cpp.o.requires
CMakeFiles/constructor_test.dir/requires: CMakeFiles/constructor_test.dir/src/ll.cpp.o.requires
CMakeFiles/constructor_test.dir/requires: CMakeFiles/constructor_test.dir/src/snakebody.cpp.o.requires

.PHONY : CMakeFiles/constructor_test.dir/requires

CMakeFiles/constructor_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/constructor_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/constructor_test.dir/clean

CMakeFiles/constructor_test.dir/depend:
	cd /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724 /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724 /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug /Users/Joshua/CLionProjects/snake-linked-list-joshuakim0724/cmake-build-debug/CMakeFiles/constructor_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/constructor_test.dir/depend
