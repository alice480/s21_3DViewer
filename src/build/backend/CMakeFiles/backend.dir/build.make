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
include backend/CMakeFiles/backend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include backend/CMakeFiles/backend.dir/compiler_depend.make

# Include the progress variables for this target.
include backend/CMakeFiles/backend.dir/progress.make

# Include the compile flags for this target's objects.
include backend/CMakeFiles/backend.dir/flags.make

backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o: backend/CMakeFiles/backend.dir/flags.make
backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o: backend/backend_autogen/mocs_compilation.cpp
backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o: backend/CMakeFiles/backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o -MF CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o -c /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend/backend_autogen/mocs_compilation.cpp

backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.i"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend/backend_autogen/mocs_compilation.cpp > CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.i

backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.s"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend/backend_autogen/mocs_compilation.cpp -o CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.s

backend/CMakeFiles/backend.dir/objparser.c.o: backend/CMakeFiles/backend.dir/flags.make
backend/CMakeFiles/backend.dir/objparser.c.o: ../backend/objparser.c
backend/CMakeFiles/backend.dir/objparser.c.o: backend/CMakeFiles/backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object backend/CMakeFiles/backend.dir/objparser.c.o"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT backend/CMakeFiles/backend.dir/objparser.c.o -MF CMakeFiles/backend.dir/objparser.c.o.d -o CMakeFiles/backend.dir/objparser.c.o -c /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/objparser.c

backend/CMakeFiles/backend.dir/objparser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/backend.dir/objparser.c.i"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/objparser.c > CMakeFiles/backend.dir/objparser.c.i

backend/CMakeFiles/backend.dir/objparser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/backend.dir/objparser.c.s"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/objparser.c -o CMakeFiles/backend.dir/objparser.c.s

backend/CMakeFiles/backend.dir/affinity.c.o: backend/CMakeFiles/backend.dir/flags.make
backend/CMakeFiles/backend.dir/affinity.c.o: ../backend/affinity.c
backend/CMakeFiles/backend.dir/affinity.c.o: backend/CMakeFiles/backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object backend/CMakeFiles/backend.dir/affinity.c.o"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT backend/CMakeFiles/backend.dir/affinity.c.o -MF CMakeFiles/backend.dir/affinity.c.o.d -o CMakeFiles/backend.dir/affinity.c.o -c /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/affinity.c

backend/CMakeFiles/backend.dir/affinity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/backend.dir/affinity.c.i"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/affinity.c > CMakeFiles/backend.dir/affinity.c.i

backend/CMakeFiles/backend.dir/affinity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/backend.dir/affinity.c.s"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend/affinity.c -o CMakeFiles/backend.dir/affinity.c.s

# Object files for target backend
backend_OBJECTS = \
"CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/backend.dir/objparser.c.o" \
"CMakeFiles/backend.dir/affinity.c.o"

# External object files for target backend
backend_EXTERNAL_OBJECTS =

backend/libbackend.a: backend/CMakeFiles/backend.dir/backend_autogen/mocs_compilation.cpp.o
backend/libbackend.a: backend/CMakeFiles/backend.dir/objparser.c.o
backend/libbackend.a: backend/CMakeFiles/backend.dir/affinity.c.o
backend/libbackend.a: backend/CMakeFiles/backend.dir/build.make
backend/libbackend.a: backend/CMakeFiles/backend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libbackend.a"
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && $(CMAKE_COMMAND) -P CMakeFiles/backend.dir/cmake_clean_target.cmake
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/backend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
backend/CMakeFiles/backend.dir/build: backend/libbackend.a
.PHONY : backend/CMakeFiles/backend.dir/build

backend/CMakeFiles/backend.dir/clean:
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend && $(CMAKE_COMMAND) -P CMakeFiles/backend.dir/cmake_clean.cmake
.PHONY : backend/CMakeFiles/backend.dir/clean

backend/CMakeFiles/backend.dir/depend:
	cd /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/backend /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend /home/alice/School21/test_viewer/C8_3DViewer_v1.0-1/src/build/backend/CMakeFiles/backend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : backend/CMakeFiles/backend.dir/depend

