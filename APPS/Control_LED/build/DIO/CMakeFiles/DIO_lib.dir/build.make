# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build"

# Include any dependencies generated for this target.
include DIO/CMakeFiles/DIO_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include DIO/CMakeFiles/DIO_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include DIO/CMakeFiles/DIO_lib.dir/progress.make

# Include the compile flags for this target's objects.
include DIO/CMakeFiles/DIO_lib.dir/flags.make

DIO/CMakeFiles/DIO_lib.dir/codegen:
.PHONY : DIO/CMakeFiles/DIO_lib.dir/codegen

DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj: DIO/CMakeFiles/DIO_lib.dir/flags.make
DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj: C:/ITI\ Intake-45\ 9\ Months/github_repos/AVR/COTS/MCAL/DIO/src/DIO_CFG.c
DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj: DIO/CMakeFiles/DIO_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj -MF CMakeFiles\DIO_lib.dir\src\DIO_CFG.c.obj.d -o CMakeFiles\DIO_lib.dir\src\DIO_CFG.c.obj -c "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\DIO_CFG.c"

DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.i"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\DIO_CFG.c" > CMakeFiles\DIO_lib.dir\src\DIO_CFG.c.i

DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.s"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\DIO_CFG.c" -o CMakeFiles\DIO_lib.dir\src\DIO_CFG.c.s

DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj: DIO/CMakeFiles/DIO_lib.dir/flags.make
DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj: C:/ITI\ Intake-45\ 9\ Months/github_repos/AVR/COTS/MCAL/DIO/src/dio.c
DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj: DIO/CMakeFiles/DIO_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj -MF CMakeFiles\DIO_lib.dir\src\dio.c.obj.d -o CMakeFiles\DIO_lib.dir\src\dio.c.obj -c "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\dio.c"

DIO/CMakeFiles/DIO_lib.dir/src/dio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DIO_lib.dir/src/dio.c.i"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\dio.c" > CMakeFiles\DIO_lib.dir\src\dio.c.i

DIO/CMakeFiles/DIO_lib.dir/src/dio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DIO_lib.dir/src/dio.c.s"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO\src\dio.c" -o CMakeFiles\DIO_lib.dir\src\dio.c.s

# Object files for target DIO_lib
DIO_lib_OBJECTS = \
"CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj" \
"CMakeFiles/DIO_lib.dir/src/dio.c.obj"

# External object files for target DIO_lib
DIO_lib_EXTERNAL_OBJECTS =

DIO/libDIO_lib.a: DIO/CMakeFiles/DIO_lib.dir/src/DIO_CFG.c.obj
DIO/libDIO_lib.a: DIO/CMakeFiles/DIO_lib.dir/src/dio.c.obj
DIO/libDIO_lib.a: DIO/CMakeFiles/DIO_lib.dir/build.make
DIO/libDIO_lib.a: DIO/CMakeFiles/DIO_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libDIO_lib.a"
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && $(CMAKE_COMMAND) -P CMakeFiles\DIO_lib.dir\cmake_clean_target.cmake
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DIO_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DIO/CMakeFiles/DIO_lib.dir/build: DIO/libDIO_lib.a
.PHONY : DIO/CMakeFiles/DIO_lib.dir/build

DIO/CMakeFiles/DIO_lib.dir/clean:
	cd /d C:\ITIINT~1\GITHUB~1\AVR\APPS\CONTRO~1\build\DIO && $(CMAKE_COMMAND) -P CMakeFiles\DIO_lib.dir\cmake_clean.cmake
.PHONY : DIO/CMakeFiles/DIO_lib.dir/clean

DIO/CMakeFiles/DIO_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED" "C:\ITI Intake-45 9 Months\github_repos\AVR\COTS\MCAL\DIO" "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build" "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build\DIO" "C:\ITI Intake-45 9 Months\github_repos\AVR\APPS\Control_LED\build\DIO\CMakeFiles\DIO_lib.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : DIO/CMakeFiles/DIO_lib.dir/depend

