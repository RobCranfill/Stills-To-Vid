cmake_minimum_required(VERSION 2.8)
project(MakeVid)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MakeVid MakeVid.cpp)
add_executable(MakeVidC MakeVid.c)

target_link_libraries(MakeVid  ${OpenCV_LIBS})
target_link_libraries(MakeVidC ${OpenCV_LIBS})

