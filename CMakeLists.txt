cmake_minimum_required(VERSION 3.22)
project(pddriver C)

set(CMAKE_C_STANDARD 17)

set(BUILD_SHARED_LIBS OFF)
add_subdirectory(3rdparty/hidapi)

# log.c library
add_library( log-c
    3rdparty/log.c/src/log.c
    3rdparty/log.c/src/log.h
)
include_directories(3rdparty/log.c/src/)


add_executable(pddriver main.c config.h)
target_link_libraries(pddriver hidapi-libusb log-c)