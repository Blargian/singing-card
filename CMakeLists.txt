cmake_minimum_required(VERSION 3.19)
project(SINGINGCARD LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

include(cmake/lto.cmake)
include(cmake/arduino_core.cmake)
include(cmake/arduino_hex.cmake)
include(cmake/arduino_upload.cmake)

add_executable(sing inc/LowPower.h src/LowPower.cpp src/singing-card.cpp inc/singing-card.hpp inc/notes.hpp inc/songs/merry_christmas.hpp inc/songs/jingle_bells.hpp inc/songs/rudolph.hpp)
target_include_directories(sing PUBLIC inc)
target_link_libraries(sing PUBLIC ArduinoCore)
target_compile_options(sing PRIVATE
    "-Wall"
    "-Wextra"
    "-pedantic"
)
arduino_avr_hex(sing)

set(ARDUINO_PORT "/dev/ttyACM0"
    CACHE STRING "The serial port for uploading using avrdude")
arduino_avr_upload(sing ${ARDUINO_PORT})