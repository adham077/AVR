macro(generate_proteus target_file target_name)
    
    add_custom_command(TARGET ${target_file} POST_BUILD
    COMMAND avr-objcopy -O ihex $<TARGET_FILE:${target_file}> ${CMAKE_BINARY_DIR}/${target_name}.hex
    COMMENT "Generating HEX file for AVR microcontroller"
    )

endmacro()
