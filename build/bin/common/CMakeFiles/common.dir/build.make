# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/monika

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/monika/build

# Include any dependencies generated for this target.
include bin/common/CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include bin/common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include bin/common/CMakeFiles/common.dir/flags.make

bin/common/CMakeFiles/common.dir/Config.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/Config.cpp.o: ../src/common/Config.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/Config.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/Config.cpp.o -c /root/monika/src/common/Config.cpp

bin/common/CMakeFiles/common.dir/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/Config.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/Config.cpp > CMakeFiles/common.dir/Config.cpp.i

bin/common/CMakeFiles/common.dir/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/Config.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/Config.cpp -o CMakeFiles/common.dir/Config.cpp.s

bin/common/CMakeFiles/common.dir/Config.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/Config.cpp.o.requires

bin/common/CMakeFiles/common.dir/Config.cpp.o.provides: bin/common/CMakeFiles/common.dir/Config.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/Config.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/Config.cpp.o.provides

bin/common/CMakeFiles/common.dir/Config.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/Config.cpp.o

bin/common/CMakeFiles/common.dir/Logger.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/Logger.cpp.o: ../src/common/Logger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/Logger.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/Logger.cpp.o -c /root/monika/src/common/Logger.cpp

bin/common/CMakeFiles/common.dir/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/Logger.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/Logger.cpp > CMakeFiles/common.dir/Logger.cpp.i

bin/common/CMakeFiles/common.dir/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/Logger.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/Logger.cpp -o CMakeFiles/common.dir/Logger.cpp.s

bin/common/CMakeFiles/common.dir/Logger.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/Logger.cpp.o.requires

bin/common/CMakeFiles/common.dir/Logger.cpp.o.provides: bin/common/CMakeFiles/common.dir/Logger.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/Logger.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/Logger.cpp.o.provides

bin/common/CMakeFiles/common.dir/Logger.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/Logger.cpp.o

bin/common/CMakeFiles/common.dir/TcpServer.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/TcpServer.cpp.o: ../src/common/TcpServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/TcpServer.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/TcpServer.cpp.o -c /root/monika/src/common/TcpServer.cpp

bin/common/CMakeFiles/common.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/TcpServer.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/TcpServer.cpp > CMakeFiles/common.dir/TcpServer.cpp.i

bin/common/CMakeFiles/common.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/TcpServer.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/TcpServer.cpp -o CMakeFiles/common.dir/TcpServer.cpp.s

bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.requires

bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.provides: bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.provides

bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/TcpServer.cpp.o

bin/common/CMakeFiles/common.dir/Connection.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/Connection.cpp.o: ../src/common/Connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/Connection.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/Connection.cpp.o -c /root/monika/src/common/Connection.cpp

bin/common/CMakeFiles/common.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/Connection.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/Connection.cpp > CMakeFiles/common.dir/Connection.cpp.i

bin/common/CMakeFiles/common.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/Connection.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/Connection.cpp -o CMakeFiles/common.dir/Connection.cpp.s

bin/common/CMakeFiles/common.dir/Connection.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/Connection.cpp.o.requires

bin/common/CMakeFiles/common.dir/Connection.cpp.o.provides: bin/common/CMakeFiles/common.dir/Connection.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/Connection.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/Connection.cpp.o.provides

bin/common/CMakeFiles/common.dir/Connection.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/Connection.cpp.o

bin/common/CMakeFiles/common.dir/ServicePool.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/ServicePool.cpp.o: ../src/common/ServicePool.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/ServicePool.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/ServicePool.cpp.o -c /root/monika/src/common/ServicePool.cpp

bin/common/CMakeFiles/common.dir/ServicePool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/ServicePool.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/ServicePool.cpp > CMakeFiles/common.dir/ServicePool.cpp.i

bin/common/CMakeFiles/common.dir/ServicePool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/ServicePool.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/ServicePool.cpp -o CMakeFiles/common.dir/ServicePool.cpp.s

bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.requires

bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.provides: bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.provides

bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/ServicePool.cpp.o

bin/common/CMakeFiles/common.dir/Time.cpp.o: bin/common/CMakeFiles/common.dir/flags.make
bin/common/CMakeFiles/common.dir/Time.cpp.o: ../src/common/Time.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/monika/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/common/CMakeFiles/common.dir/Time.cpp.o"
	cd /root/monika/build/bin/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/Time.cpp.o -c /root/monika/src/common/Time.cpp

bin/common/CMakeFiles/common.dir/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/Time.cpp.i"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/monika/src/common/Time.cpp > CMakeFiles/common.dir/Time.cpp.i

bin/common/CMakeFiles/common.dir/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/Time.cpp.s"
	cd /root/monika/build/bin/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/monika/src/common/Time.cpp -o CMakeFiles/common.dir/Time.cpp.s

bin/common/CMakeFiles/common.dir/Time.cpp.o.requires:
.PHONY : bin/common/CMakeFiles/common.dir/Time.cpp.o.requires

bin/common/CMakeFiles/common.dir/Time.cpp.o.provides: bin/common/CMakeFiles/common.dir/Time.cpp.o.requires
	$(MAKE) -f bin/common/CMakeFiles/common.dir/build.make bin/common/CMakeFiles/common.dir/Time.cpp.o.provides.build
.PHONY : bin/common/CMakeFiles/common.dir/Time.cpp.o.provides

bin/common/CMakeFiles/common.dir/Time.cpp.o.provides.build: bin/common/CMakeFiles/common.dir/Time.cpp.o

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/Config.cpp.o" \
"CMakeFiles/common.dir/Logger.cpp.o" \
"CMakeFiles/common.dir/TcpServer.cpp.o" \
"CMakeFiles/common.dir/Connection.cpp.o" \
"CMakeFiles/common.dir/ServicePool.cpp.o" \
"CMakeFiles/common.dir/Time.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/Config.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/Logger.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/TcpServer.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/Connection.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/ServicePool.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/Time.cpp.o
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/build.make
bin/common/libcommon.so: bin/common/CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libcommon.so"
	cd /root/monika/build/bin/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/common/CMakeFiles/common.dir/build: bin/common/libcommon.so
.PHONY : bin/common/CMakeFiles/common.dir/build

bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/Config.cpp.o.requires
bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/Logger.cpp.o.requires
bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/TcpServer.cpp.o.requires
bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/Connection.cpp.o.requires
bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/ServicePool.cpp.o.requires
bin/common/CMakeFiles/common.dir/requires: bin/common/CMakeFiles/common.dir/Time.cpp.o.requires
.PHONY : bin/common/CMakeFiles/common.dir/requires

bin/common/CMakeFiles/common.dir/clean:
	cd /root/monika/build/bin/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : bin/common/CMakeFiles/common.dir/clean

bin/common/CMakeFiles/common.dir/depend:
	cd /root/monika/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/monika /root/monika/src/common /root/monika/build /root/monika/build/bin/common /root/monika/build/bin/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/common/CMakeFiles/common.dir/depend

