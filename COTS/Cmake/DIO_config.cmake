macro(generate_configuration)
    find_package(Python3 REQUIRED)
    find_program(CONFIG_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/dio_config.py REQUIRED)
    set(CONFIG_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/configuration.h")

    set(PORTS "" CACHE STRING "Space-separated list of ports (e.g., 'PORTA PORTB PORTC')")
    message(STATUS "Portss selected: ${PORTS}")

    string(REPLACE " " ";" PORTS_LIST "${PORTS}")

    add_custom_command(
        OUTPUT "${CONFIG_HEADER}"
        COMMAND ${Python3_EXECUTABLE} ${CONFIG_SCRIPT} ${PORTS_LIST}
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "Generating configuration header for operations: ${PORTS}"
    )

    add_custom_target(
        generate_config ALL
        DEPENDS "${CONFIG_HEADER}"
    )

    #add_dependencies(app generate_config)
endmacro()