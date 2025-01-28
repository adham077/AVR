macro(flash target_file target_name)
    
    add_custom_command(TARGET ${target_file} POST_BUILD
        COMMAND avrdude -c usbasp -p m32 -U flash:w:${CMAKE_BINARY_DIR}/${target_name}.hex:i
        COMMENT "Flashing ATmega32 using USBasp"
    )

endmacro()