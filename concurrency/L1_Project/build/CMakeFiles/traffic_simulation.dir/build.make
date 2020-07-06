# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amirok/Documents/UdacityCpp/concurrency/L1_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build

# Include any dependencies generated for this target.
include CMakeFiles/traffic_simulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/traffic_simulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traffic_simulation.dir/flags.make

CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o: ../src/Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Graphics.cpp

CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Graphics.cpp > CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.i

CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Graphics.cpp -o CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.s

CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o: ../src/Intersection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Intersection.cpp

CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Intersection.cpp > CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.i

CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Intersection.cpp -o CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.s

CMakeFiles/traffic_simulation.dir/src/Street.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/Street.cpp.o: ../src/Street.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/traffic_simulation.dir/src/Street.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/Street.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Street.cpp

CMakeFiles/traffic_simulation.dir/src/Street.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/Street.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Street.cpp > CMakeFiles/traffic_simulation.dir/src/Street.cpp.i

CMakeFiles/traffic_simulation.dir/src/Street.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/Street.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Street.cpp -o CMakeFiles/traffic_simulation.dir/src/Street.cpp.s

CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o: ../src/TrafficObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficObject.cpp

CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficObject.cpp > CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.i

CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficObject.cpp -o CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.s

CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o: ../src/TrafficSimulator-L1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficSimulator-L1.cpp

CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficSimulator-L1.cpp > CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.i

CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/TrafficSimulator-L1.cpp -o CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.s

CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o: CMakeFiles/traffic_simulation.dir/flags.make
CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o: ../src/Vehicle_Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o -c /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Vehicle_Student.cpp

CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Vehicle_Student.cpp > CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.i

CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/src/Vehicle_Student.cpp -o CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.s

# Object files for target traffic_simulation
traffic_simulation_OBJECTS = \
"CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o" \
"CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o" \
"CMakeFiles/traffic_simulation.dir/src/Street.cpp.o" \
"CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o" \
"CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o" \
"CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o"

# External object files for target traffic_simulation
traffic_simulation_EXTERNAL_OBJECTS =

traffic_simulation: CMakeFiles/traffic_simulation.dir/src/Graphics.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/src/Intersection.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/src/Street.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/src/TrafficObject.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/src/TrafficSimulator-L1.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/src/Vehicle_Student.cpp.o
traffic_simulation: CMakeFiles/traffic_simulation.dir/build.make
traffic_simulation: /usr/local/lib/libopencv_dnn.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_gapi.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_highgui.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_ml.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_objdetect.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_photo.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_stitching.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_video.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_videoio.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_imgcodecs.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_calib3d.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_features2d.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_flann.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_imgproc.so.4.4.0
traffic_simulation: /usr/local/lib/libopencv_core.so.4.4.0
traffic_simulation: CMakeFiles/traffic_simulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable traffic_simulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traffic_simulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traffic_simulation.dir/build: traffic_simulation

.PHONY : CMakeFiles/traffic_simulation.dir/build

CMakeFiles/traffic_simulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/traffic_simulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/traffic_simulation.dir/clean

CMakeFiles/traffic_simulation.dir/depend:
	cd /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amirok/Documents/UdacityCpp/concurrency/L1_Project /home/amirok/Documents/UdacityCpp/concurrency/L1_Project /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build /home/amirok/Documents/UdacityCpp/concurrency/L1_Project/build/CMakeFiles/traffic_simulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/traffic_simulation.dir/depend

