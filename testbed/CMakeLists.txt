cmake_minimum_required(VERSION 3.5)
project(testbed)

# cmake config

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# linking

add_executable(testbed 
    src/main.cpp 
    )

target_include_directories(testbed PRIVATE ../core/src)

target_link_libraries(testbed PRIVATE 
    engine
    ) 