cmake_minimum_required(VERSION 2.8)


project(the_trip)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(the_trip_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(the_trip_run src)