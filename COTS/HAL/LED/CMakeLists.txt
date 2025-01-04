CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0)
project(LED_lib C)

set(MCAL_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL")

#add_subdirectory(${MCAL_LIB_PATH}  "${CMAKE_BINARY_DIR}/MCAL") 
add_library(LED_lib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LED.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LED_CFG.c
)

target_link_libraries(LED_lib PUBLIC MCAL_lib)   

target_include_directories(LED_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

