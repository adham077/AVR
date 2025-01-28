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

set(HAL_LIBS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/HAL")
set(CMAKE_MACROS_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/CMAKE")

include(${CMAKE_MACROS_PATH}/hex.cmake)
include(${CMAKE_MACROS_PATH}/flash.cmake)

cmake_minimum_required(VERSION 3.11.0)
project(hal_test C)

add_executable(hal_test "${CMAKE_CURRENT_SOURCE_DIR}/src/hal_test.c")
add_subdirectory(${HAL_LIBS_PATH}  "${CMAKE_BINARY_DIR}/HAL_LIBS")

target_link_libraries(hal_test 
    PRIVATE HAL_lib
    )
generate_hex("hal_test" "leds_test")

if(HW STREQUAL "ON")
    flash("hal_test" "leds_test")
endif()