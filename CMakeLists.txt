add_library(pico_sh1106
        sh1106.cpp
        frameBuffer/FrameBuffer.cpp
        shapeRenderer/ShapeRenderer.cpp)

add_subdirectory(textRenderer)

target_link_libraries(pico_sh1106
        sh1106_textRenderer
        hardware_i2c
        pico_stdlib
        )
target_include_directories (pico_sh1106 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})