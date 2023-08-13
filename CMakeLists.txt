cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(watering_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)
pico_sdk_init()

add_executable(wifi_scan
  wifi_scan.c
)

pico_enable_stdio_usb(wifi_scan 1)
pico_enable_stdio_uart(wifi_scan 1)

pico_add_extra_outputs(wifi_scan)

target_include_directories( wifi_scan PRIVATE ${CMAKE_CURRENT_LIST_DIR} )

target_link_libraries(wifi_scan
        pico_cyw43_arch_lwip_threadsafe_background
        pico_stdlib
        )