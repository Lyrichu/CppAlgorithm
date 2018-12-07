cmake_minimum_required(VERSION 3.10)
project(CppAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppAlgorithm tools/zlib/compress/zlib_compress_demo.cpp)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()