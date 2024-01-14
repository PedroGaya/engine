# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/gaya/git/c++/engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gaya/git/c++/engine/build

# Utility rule file for png_scripts_sym_out.

# Include any custom commands dependencies for this target.
include include/libpng/CMakeFiles/png_scripts_sym_out.dir/compiler_depend.make

# Include the progress variables for this target.
include include/libpng/CMakeFiles/png_scripts_sym_out.dir/progress.make

include/libpng/CMakeFiles/png_scripts_sym_out: include/libpng/scripts/sym.out

include/libpng/scripts/sym.out: /home/gaya/git/c++/engine/include/libpng/scripts/sym.c
include/libpng/scripts/sym.out: include/libpng/pnglibconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gaya/git/c++/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating scripts/sym.out"
	cd /home/gaya/git/c++/engine/build/include/libpng && /usr/bin/cmake -DINPUT=/home/gaya/git/c++/engine/include/libpng/scripts/sym.c -DOUTPUT=/home/gaya/git/c++/engine/build/include/libpng/scripts/sym.out -P /home/gaya/git/c++/engine/build/include/libpng/scripts/genout.cmake

include/libpng/pnglibconf.h: include/libpng/pnglibconf.out
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gaya/git/c++/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating pnglibconf.h"
	cd /home/gaya/git/c++/engine/build/include/libpng && /usr/bin/cmake -DOUTPUT=pnglibconf.h -P /home/gaya/git/c++/engine/build/include/libpng/scripts/gensrc.cmake

include/libpng/pnglibconf.out: include/libpng/pnglibconf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gaya/git/c++/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating pnglibconf.out"
	cd /home/gaya/git/c++/engine/build/include/libpng && /usr/bin/cmake -DINPUT=/home/gaya/git/c++/engine/build/include/libpng/pnglibconf.c -DOUTPUT=/home/gaya/git/c++/engine/build/include/libpng/pnglibconf.out -P /home/gaya/git/c++/engine/build/include/libpng/scripts/genout.cmake

include/libpng/pnglibconf.c: /home/gaya/git/c++/engine/include/libpng/scripts/pnglibconf.dfa
include/libpng/pnglibconf.c: include/libpng/scripts/options.awk
include/libpng/pnglibconf.c: /home/gaya/git/c++/engine/include/libpng/pngconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gaya/git/c++/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating pnglibconf.c"
	cd /home/gaya/git/c++/engine/build/include/libpng && /usr/bin/cmake -DOUTPUT=pnglibconf.c -P /home/gaya/git/c++/engine/build/include/libpng/scripts/gensrc.cmake

png_scripts_sym_out: include/libpng/CMakeFiles/png_scripts_sym_out
png_scripts_sym_out: include/libpng/pnglibconf.c
png_scripts_sym_out: include/libpng/pnglibconf.h
png_scripts_sym_out: include/libpng/pnglibconf.out
png_scripts_sym_out: include/libpng/scripts/sym.out
png_scripts_sym_out: include/libpng/CMakeFiles/png_scripts_sym_out.dir/build.make
.PHONY : png_scripts_sym_out

# Rule to build all files generated by this target.
include/libpng/CMakeFiles/png_scripts_sym_out.dir/build: png_scripts_sym_out
.PHONY : include/libpng/CMakeFiles/png_scripts_sym_out.dir/build

include/libpng/CMakeFiles/png_scripts_sym_out.dir/clean:
	cd /home/gaya/git/c++/engine/build/include/libpng && $(CMAKE_COMMAND) -P CMakeFiles/png_scripts_sym_out.dir/cmake_clean.cmake
.PHONY : include/libpng/CMakeFiles/png_scripts_sym_out.dir/clean

include/libpng/CMakeFiles/png_scripts_sym_out.dir/depend:
	cd /home/gaya/git/c++/engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gaya/git/c++/engine /home/gaya/git/c++/engine/include/libpng /home/gaya/git/c++/engine/build /home/gaya/git/c++/engine/build/include/libpng /home/gaya/git/c++/engine/build/include/libpng/CMakeFiles/png_scripts_sym_out.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : include/libpng/CMakeFiles/png_scripts_sym_out.dir/depend

