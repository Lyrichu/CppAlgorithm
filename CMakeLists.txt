cmake_minimum_required(VERSION 3.10)
project(CppAlgorithm)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES tools/boost/basic/tuple/make_tuple_demo.cpp)
add_executable(CppAlgorithm ${SOURCE_FILES})

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

target_link_libraries(CppAlgorithm ${CONAN_LIBS})