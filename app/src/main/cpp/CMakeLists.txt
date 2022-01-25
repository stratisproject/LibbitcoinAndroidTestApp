# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("staticlibraryplayground")

add_library(
        libbitcoin-system
        STATIC
        IMPORTED
)
set_target_properties(libbitcoin-system PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libbitcoin-system.a)

add_library(
        boost-atomic
        STATIC
        IMPORTED
)
set_target_properties(boost-atomic PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_atomic.a)

add_library(
        boost-chrono
        STATIC
        IMPORTED
)
set_target_properties(boost-chrono PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_chrono.a)

add_library(
        boost-datetime
        STATIC
        IMPORTED
)
set_target_properties(boost-datetime PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_date_time.a)

add_library(
        boost-filesystem
        STATIC
        IMPORTED
)
set_target_properties(boost-filesystem PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_filesystem.a)

add_library(
        boost-iostreams
        STATIC
        IMPORTED
)
set_target_properties(boost-iostreams PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_iostreams.a)

add_library(
        boost-locale
        STATIC
        IMPORTED
)
set_target_properties(boost-locale PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_locale.a)

add_library(
        boost-log
        STATIC
        IMPORTED
)
set_target_properties(boost-log PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_log.a)

add_library(
        boost-log-setup
        STATIC
        IMPORTED
)
set_target_properties(boost-log-setup PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_log_setup.a)

add_library(
        boost-prg-exec-monitor
        STATIC
        IMPORTED
)
set_target_properties(boost-prg-exec-monitor PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_prg_exec_monitor.a)

add_library(
        boost-program-options
        STATIC
        IMPORTED
)
set_target_properties(boost-program-options PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_program_options.a)

add_library(
        boost-regex
        STATIC
        IMPORTED
)
set_target_properties(boost-regex PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_regex.a)

add_library(
        boost-system
        STATIC
        IMPORTED
)
set_target_properties(boost-system PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_system.a)

add_library(
        boost-test-exec-monitor
        STATIC
        IMPORTED
)
set_target_properties(boost-test-exec-monitor PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_test_exec_monitor.a)

add_library(
        boost-thread
        STATIC
        IMPORTED
)
set_target_properties(boost-thread PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_thread.a)

add_library(
        boost-unit-test-framework
        STATIC
        IMPORTED
)
set_target_properties(boost-unit-test-framework PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libboost_unit_test_framework.a)

add_library(
        secp256k1
        STATIC
        IMPORTED
)
set_target_properties(secp256k1 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libsecp256k1.a)


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        staticlibraryplayground

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_include_directories( staticlibraryplayground PRIVATE
        ${CMAKE_SOURCE_DIR}/include )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        staticlibraryplayground

        libbitcoin-system
        boost-atomic
        boost-chrono
        boost-datetime
        boost-filesystem
        boost-iostreams
        boost-locale
        boost-log
        boost-log-setup
        boost-prg-exec-monitor
        boost-program-options
        boost-regex
        boost-system
        boost-test-exec-monitor
        boost-thread
        boost-unit-test-framework
        secp256k1

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})