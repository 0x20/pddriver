cmake_minimum_required(VERSION 3.22)
project(pddriver
        VERSION 0.1.0
        DESCRIPTION "USB HID Presence Detect Sensory Driver"
        HOMEPAGE_URL "https://wiki.hackerspace.gent/Spacebar"
        LANGUAGES C)

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

set(PROGRAM_PERMISSIONS_DEFAULT
        OWNER_WRITE OWNER_READ OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE)
install(TARGETS pddriver DESTINATION bin PERMISSIONS ${PROGRAM_PERMISSIONS_DEFAULT} SETUID)


set(CPACK_PACKAGE_VENDOR "hackerspace.gent")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "yvanj@cyber.gent")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Yvan Janssens")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libudev1, libusb-1.0-0, xdotool" )

include(CPack)
