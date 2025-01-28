#set(CMAKE_SYSTEM_NAME Generic)
#set(CMAKE_SYSTEM_PROCESSOR avr)
#set(CMAKE_C_COMPILER avr-gcc)
#set(CMAKE_CXX_COMPILER avr-g++)
#set(CMAKE_AR avr-ar)
#set(CMAKE_OBJCOPY avr-objcopy)
#set(CMAKE_OBJDUMP avr-objdump)
#set(CMAKE_LINKER avr-ld)
#set(CMAKE_C_FLAGS "-mmcu=atmega32 -Wall -Os")
#set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -Wall -Os")
#set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0)
project(PORT_lib C)

add_library(PORT_lib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PORT_CFG.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PORT.c
)

target_include_directories(PORT_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../STD_LIB
)