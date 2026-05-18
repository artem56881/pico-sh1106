cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(multiple_displays)

pico_sdk_init()

add_subdirectory(pico-sh1106)

add_executable(multiple_displays_example
        main.cpp)

target_link_libraries(multiple_displays_example
        hardware_i2c
        pico_sh1106)


pico_add_extra_outputs(multiple_displays)
