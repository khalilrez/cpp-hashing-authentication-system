cmake_minimum_required(VERSION 3.27)
project(cpp_sha_256_authentication)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_sha_256_authentication main.cpp
        auth.h
        auth.cpp)
