cmake_minimum_required(VERSION 3.14)
project(utils_tools)
enable_testing()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
include_directories(src)
set(UTILS_SOURCE_DIR .)
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    option(WITH_TESTS "Build tests" ON)
    if (WITH_TESTS)
        message(STATUS "Building tests enabled")
        add_subdirectory(test)
    else ()
        message(STATUS "Building tests disabled")
    endif ()

    option(WITH_TUTORIALS "Build tutorials" ON)
    if (WITH_TUTORIALS)
        message(STATUS "Building tutorials enabled")
        add_subdirectory(tutorial)
    else ()
        message(STATUS "Building tutorials disabled")
    endif ()

    option(WITH_DOCS "Build documentation" OFF)
    if (WITH_DOCS)
        message(STATUS "Building docs enabled")
        add_subdirectory(doc)
    else ()
        message(STATUS "Building docs disabled")
    endif ()

    option(WITH_UTILS "Build utils" ON)
    if (WITH_UTILS)
        message(STATUS "Building utils enabled")
        add_subdirectory(util)
    else ()
        message(STATUS "Building utils disabled")
    endif ()


    if (TARGET clang-format AND NOT WIN32)
        add_custom_target(format COMMAND
                          find
                          "${UTILS_SOURCE_DIR}/src"
                          "${UTILS_SOURCE_DIR}/tools"
                          "${UTILS_SOURCE_DIR}/test"
                          -name *.cpp -o -name *.h -o -name *.c |
                          xargs $<TARGET_FILE:clang-format> -i -style=file)
    endif ()
endif ()


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} utils)
