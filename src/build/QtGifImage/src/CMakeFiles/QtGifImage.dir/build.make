# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build

# Include any dependencies generated for this target.
include QtGifImage/src/CMakeFiles/QtGifImage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include QtGifImage/src/CMakeFiles/QtGifImage.dir/compiler_depend.make

# Include the progress variables for this target.
include QtGifImage/src/CMakeFiles/QtGifImage.dir/progress.make

# Include the compile flags for this target's objects.
include QtGifImage/src/CMakeFiles/QtGifImage.dir/flags.make

QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o: QtGifImage/src/CMakeFiles/QtGifImage.dir/flags.make
QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o: QtGifImage/src/QtGifImage_autogen/mocs_compilation.cpp
QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o: QtGifImage/src/CMakeFiles/QtGifImage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o -MF CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o -c /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src/QtGifImage_autogen/mocs_compilation.cpp

QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.i"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src/QtGifImage_autogen/mocs_compilation.cpp > CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.i

QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.s"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src/QtGifImage_autogen/mocs_compilation.cpp -o CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.s

QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o: QtGifImage/src/CMakeFiles/QtGifImage.dir/flags.make
QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o: ../QtGifImage/src/gifimage/qgifimage.cpp
QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o: QtGifImage/src/CMakeFiles/QtGifImage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o -MF CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o.d -o CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o -c /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/QtGifImage/src/gifimage/qgifimage.cpp

QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.i"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/QtGifImage/src/gifimage/qgifimage.cpp > CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.i

QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.s"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/QtGifImage/src/gifimage/qgifimage.cpp -o CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.s

# Object files for target QtGifImage
QtGifImage_OBJECTS = \
"CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o"

# External object files for target QtGifImage
QtGifImage_EXTERNAL_OBJECTS =

QtGifImage/src/libQtGifImage.a: QtGifImage/src/CMakeFiles/QtGifImage.dir/QtGifImage_autogen/mocs_compilation.cpp.o
QtGifImage/src/libQtGifImage.a: QtGifImage/src/CMakeFiles/QtGifImage.dir/gifimage/qgifimage.cpp.o
QtGifImage/src/libQtGifImage.a: QtGifImage/src/CMakeFiles/QtGifImage.dir/build.make
QtGifImage/src/libQtGifImage.a: QtGifImage/src/CMakeFiles/QtGifImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libQtGifImage.a"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && $(CMAKE_COMMAND) -P CMakeFiles/QtGifImage.dir/cmake_clean_target.cmake
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtGifImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
QtGifImage/src/CMakeFiles/QtGifImage.dir/build: QtGifImage/src/libQtGifImage.a
.PHONY : QtGifImage/src/CMakeFiles/QtGifImage.dir/build

QtGifImage/src/CMakeFiles/QtGifImage.dir/clean:
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src && $(CMAKE_COMMAND) -P CMakeFiles/QtGifImage.dir/cmake_clean.cmake
.PHONY : QtGifImage/src/CMakeFiles/QtGifImage.dir/clean

QtGifImage/src/CMakeFiles/QtGifImage.dir/depend:
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/QtGifImage/src /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/QtGifImage/src/CMakeFiles/QtGifImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QtGifImage/src/CMakeFiles/QtGifImage.dir/depend

