cmake_minimum_required(VERSION 3.3)
project(minesweeper)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# General
###############################################################################
# Activate C++0x support (if you encounter gmock errors, use 1.6.0 version)
add_definitions(-std=c++0x)
# Extra warnings
add_definitions(-Wextra)
# Google Mock & Test
###############################################################################
#add_subdirectory(${GMOCK_ROOT})
#include_directories(${GMOCK_ROOT}/include)
#include_directories(${GMOCK_ROOT}/gtest/include)
# Main program executable
###############################################################################
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
# Include root directory
include_directories(BEFORE ".")
include_directories(BEFORE "src/")

set(EXECUTABLE_NAME "program")
# Source files
file(GLOB SRC_FILES "src/*.cpp" "src/*.h")
# Executable dependencies
if(SRC_FILES)
    add_executable("${EXECUTABLE_NAME}" ${SRC_FILES} src/Minesweeper.cpp)
endif(SRC_FILES)
# Set link libraries
# target_link_libraries($EXECUTABLE_NAME ...)
# Tests executable
###############################################################################
set(TEST_EXECUTABLE_NAME "tests")
# Test files
file(GLOB TEST_FILES "test/*.cpp")
# Don't include Main.cpp from src
file(GLOB MAIN_SRC "src/Minesweeper.cpp")

#if (project_build_tests)
enable_testing()
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_FILES} ${SRC_FILES} test/Minesweeper_unittest.cpp)
target_link_libraries(${TEST_EXECUTABLE_NAME}
        pthread)
target_link_libraries(${TEST_EXECUTABLE_NAME}
        gmock
        gmock_main)
target_link_libraries(${TEST_EXECUTABLE_NAME}
        gtest
        gtest_main)
add_test(all-tests ${TEST_EXECUTABLE_NAME})
#endif()



# Set link libraries (order matters)
#target_link_libraries("${TEST_EXECUTABLE_NAME}" gmock gtest pthread)
