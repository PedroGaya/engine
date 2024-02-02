cmake_minimum_required(VERSION 3.5)
project(engine)

# cmake config

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# glfw config

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(./vendor/glfw)

# libpng config

set(PNG_STATIC ON)
set(PNG_SHARED OFF)
set(PNG_TOOL OFF)
set(PNG_TESTS OFF)
set(SKIP_INSTALL_ALL OFF) 

add_subdirectory(./vendor/libpng)

# openal-soft config

set(ALSOFT_EXAMPLES OFF)
set(ALSOFT_UTILS OFF)

add_subdirectory(./vendor/openal)

# glad config

add_subdirectory(./vendor/glad)

# glm config

set(glm_DIR ./vendor/glm/cmake/glm)
find_package(glm REQUIRED)

# linking

add_library(engine SHARED 
    src/test.cpp 
    )

target_include_directories(engine PRIVATE ./vendor)
target_link_libraries(engine PRIVATE 
    glfw 
    png 
    openal
    glad
    glm::glm
    ) 