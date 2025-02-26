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

set(PORT_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/MCAL/PORT")
set(DIO_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/MCAL/DIO")
set(CMAKE_MACROS_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/CMAKE")

include(${CMAKE_MACROS_PATH}/hex.cmake)
include(${CMAKE_MACROS_PATH}/flash.cmake)
cmake_minimum_required(VERSION 3.11.0)
project(test_leds C)
add_executable(test_leds "${CMAKE_CURRENT_SOURCE_DIR}/src/test_leds.c")
add_subdirectory(${PORT_LIB_PATH}  "${CMAKE_BINARY_DIR}/PORT")
add_subdirectory(${DIO_LIB_PATH}  "${CMAKE_BINARY_DIR}/DIO")
target_link_libraries(test_leds 
    PRIVATE DIO_lib
    PRIVATE PORT_lib    
    )
    
generate_hex("test_leds" "leds")

if(HW STREQUAL "ON")
    flash("test_leds" "leds")
endif()