set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_AR avr-ar)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_OBJDUMP avr-objdump)
set(CMAKE_LINKER avr-ld)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -Wall -Os")
set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -Wall -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

cmake_minimum_required(VERSION 3.11.0)
project(Binary_Counter C)
add_executable(Binary_Counter "src/Binary_Counter.c")

include(${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/Cmake/DIO_config.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/Cmake/proteus.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/Cmake/flash.cmake)

add_subdirectory("../../COTS/MCAL/DIO" "${CMAKE_BINARY_DIR}/DIO")
target_link_libraries(Binary_Counter PRIVATE DIO_lib)

generate_proteus("Binary_Counter" "binaryConuter")

if(HW STREQUAL "ON")
    generate_flash("Binary_Counter" "binaryCounter")
endif()

