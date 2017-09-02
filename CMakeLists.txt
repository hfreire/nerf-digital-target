cmake_minimum_required(VERSION 3.2)
project(nerf-digital-target)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

generate_arduino_firmware(nerf-digital-target
    SKETCH src/nerf-digital-target.ino
    PORT /dev/cu.usbmodem1421
    BOARD micro)
