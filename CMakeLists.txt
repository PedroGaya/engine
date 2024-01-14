cmake_minimum_required(VERSION 3.5)
project(engine)

# cmake config

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# glfw config

set(GLFW_BUILD_EXAMPLES OFF) # only lib
set(GLFW_BUILD_TESTS OFF) # only lib

add_subdirectory(./include/glfw)

# libpng config

set(PNG_STATIC ON)
set(PNG_TOOL OFF) # only lib
set(PNG_TESTS OFF) # only lib
set(SKIP_INSTALL_ALL OFF) # only lib

add_subdirectory(./include/libpng)

# glm config

add_subdirectory(./include/glm)

# entt config

add_subdirectory(./include/entt)

# openal-soft config

add_subdirectory(./include/openal)

# linking

add_executable(engine src/main.cpp src/glad.c) 
target_link_libraries(engine glfw glm::glm png openal EnTT::EnTT) # glad, stb_image, entt are header only