cmake_minimum_required(VERSION 3.10)

project(Dex VERSION 0.1 LANGUAGES CXX)

#check the things below
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download build system
set(CMAKESPARK_VERSION "3.0.2" CACHE STRING "CMakeSpark version")
if(NOT EXISTS "${CMAKE_BINARY_DIR}/buildsys/v${CMAKESPARK_VERSION}")
    message(STATUS "Downloading buildsystem...")

    set(CMAKESPARK_ARCHIVE ${CMAKE_BINARY_DIR}/buildsys/cmakespark-${CMAKESPARK_VERSION}.zip)
    file(DOWNLOAD "https://github.com/cmakespark/cmake/releases/download/v${CMAKESPARK_VERSION}/cmakespark.zip" ${CMAKESPARK_ARCHIVE} SHOW_PROGRESS)
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/buildsys/v${CMAKESPARK_VERSION})
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar vxzf ${CMAKESPARK_ARCHIVE}
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/buildsys/v${CMAKESPARK_VERSION} )
endif()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/buildsys/v${CMAKESPARK_VERSION}")

# Include common cmake modules
include(CommonConfig)

# Include packages
find_package(Qt6Core REQUIRED)

add_subdirectory(src)
#add_subdirectory(tests)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(untitled SHARED
#            ${PROJECT_SOURCES}
#        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(untitled
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()
