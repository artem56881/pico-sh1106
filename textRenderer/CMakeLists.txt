add_library(sh1106_textRenderer
        TextRenderer.cpp
        5x8_font.h
        8x8_font.h
        12x16_font.h
        16x32_font.h
        )

target_link_libraries(sh1106_textRenderer
        hardware_i2c
        pico_stdlib
        )