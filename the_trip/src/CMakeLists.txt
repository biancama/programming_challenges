cmake_minimum_required(VERSION 2.8)

project(the_trip)

add_definitions(-std=c++11)

set(SOURCE_FILES
        the_trip.cpp)

add_library(the_trip STATIC ${SOURCE_FILES})