cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(hello_max6675)
add_subdirectory(pico-max6675)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(hello_max6675
    hello_max6675.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(hello_max6675 
    max6675
    hardware_spi
    pico_stdlib
)

pico_enable_stdio_usb(hello_max6675 1)
pico_enable_stdio_uart(hello_max6675 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello_max6675)