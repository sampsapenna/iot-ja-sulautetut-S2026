cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
include(pico-sdk/pico_sdk_init.cmake)
include(pico-sdk/external/pico_sdk_import.cmake)

project(luento_3 C CXX ASM)

pico_sdk_init()

add_compile_options(-Wall
	-Wno-format
	-Wno-unused-function
	-Wno-maybe-uninitialized
	)

add_executable(int_led_example
	int_led_example.c
)

target_link_libraries(int_led_example pico_stdlib)

pico_enable_stdio_usb(int_led_example 1)
pico_enable_stdio_uart(int_led_example 0)

pico_add_extra_outputs(int_led_example)


add_executable(adc_pokery
	adc_pokery.c
)

target_link_libraries(adc_pokery pico_stdlib hardware_adc)

pico_enable_stdio_usb(adc_pokery 1)
pico_enable_stdio_uart(adc_pokery 0)

pico_add_extra_outputs(adc_pokery)

