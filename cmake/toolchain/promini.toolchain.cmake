set(ARDUINO_BOARD "PRO")
set(ARDUINO_MCU "atmega328p")
set(ARDUINO_F_CPU "16000000L")
set(ARDUINO_VARIANT "eightanaloginputs")
set(ARDUINO_AVRDUDE_PROTOCOL "arduino")
set(ARDUINO_AVRDUDE_SPEED "57600")
set(ARDUINO_USB On)
set(ARDUINO_USB_VID "0x2341")
set(ARDUINO_USB_PID "0x8037")
include(${CMAKE_CURRENT_LIST_DIR}/avr.toolchain.cmake)