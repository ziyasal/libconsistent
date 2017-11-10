cmake_minimum_required(VERSION 3.8)
project(libconsistent)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ConsistentHash.cpp ConsistentHash.h murmur3/MurmurHash3.cpp murmur3/MurmurHash3.h scopeguard/ScopeGuard.cpp scopeguard/ScopeGuard.h)
add_executable(libconsistent ${SOURCE_FILES})