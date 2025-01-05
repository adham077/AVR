CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0)
project(seven_segment_lib C)

set(MCAL_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL")

#add_subdirectory(${MCAL_LIB_PATH}  "${CMAKE_BINARY_DIR}/MCAL") 
add_library(SEVEN_SEGMENT_lib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/segment7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/segment7_cfg.c
)

target_link_libraries(SEVEN_SEGMENT_lib PUBLIC MCAL_lib)   

target_include_directories(SEVEN_SEGMENT_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

