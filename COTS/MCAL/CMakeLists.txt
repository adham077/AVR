cmake_minimum_required(VERSION 3.11.0)
project(MCAL_Drivers C)

# Define the base path for MCAL subdirectories
set(MCAL_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Create an empty list to store sub-library targets
set(MCAL_TARGETS)

# List all MCAL subdirectories
set(MCAL_SUBDIRS
    "PORT"
    "DIO"
)

# Iterate through each subdirectory and add it
foreach(SUBDIR ${MCAL_SUBDIRS})
    set(LIB_PATH "${MCAL_LIB_PATH}/${SUBDIR}")
    if (NOT TARGET ${SUBDIR}_lib)
        add_subdirectory(${LIB_PATH} "${CMAKE_BINARY_DIR}/${SUBDIR}")
        list(APPEND MCAL_TARGETS ${SUBDIR}_lib)
    endif()
endforeach()

# Create the combined MCAL library
add_library(MCAL_lib INTERFACE)

# Link all sub-libraries to MCAL_lib
target_link_libraries(MCAL_lib INTERFACE ${MCAL_TARGETS})
