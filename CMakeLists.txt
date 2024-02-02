cmake_minimum_required(VERSION 3.5)
project(engine)

# cmake config

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

# subprojects

add_subdirectory(./core)
add_subdirectory(./testbed)