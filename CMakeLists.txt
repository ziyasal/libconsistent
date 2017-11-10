cmake_minimum_required(VERSION 3.8)
project(libconsistent)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Host.cpp Host.h Consistent.cpp Consistent.h)
add_executable(libconsistent ${SOURCE_FILES})