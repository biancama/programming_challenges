cmake_minimum_required(VERSION 3.1)

project(the_trip)

add_definitions(-std=c++0x)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++" )

set(SOURCE_FILES "src/the_trip.cpp")

add_executable(the_trip_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(the_trip_run)