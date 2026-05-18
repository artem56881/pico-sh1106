cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(text_advanced)

pico_sdk_init()

add_subdirectory(pico-sh1106)

add_executable(text_advanced
        main.cpp)

target_link_libraries(text_advanced
        hardware_i2c
        pico_sh1106)


pico_add_extra_outputs(text_advanced)
