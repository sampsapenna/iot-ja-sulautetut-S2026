cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

project(iot_week_7 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(blink_and_temp
    src/main.c
    src/blink.c
    src/temp.c
    src/FreeRTOS_conv.c
        )

target_include_directories(blink_and_temp PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        src/include)

target_compile_definitions(blink_and_temp PRIVATE
        PICO_STDIO_STACK_BUFFER_SIZE=64 # use a small printf on stack buffer
)
target_link_libraries(blink_and_temp pico_stdlib hardware_adc FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)
pico_add_extra_outputs(blink_and_temp)

# Use USB uart
pico_enable_stdio_usb(blink_and_temp 1)
pico_enable_stdio_uart(blink_and_temp 1)

target_compile_options(blink_and_temp PUBLIC
        ### Gnu/Clang C Options
        $<$<COMPILE_LANG_AND_ID:C,GNU>:-fdiagnostics-color=always>
        $<$<COMPILE_LANG_AND_ID:C,Clang>:-fcolor-diagnostics>

        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wall>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wextra>
        # $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Werror>
        # $<$<COMPILE_LANG_AND_ID:C,Clang>:-Weverything>
        )
