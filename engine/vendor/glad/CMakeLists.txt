cmake_minimum_required(VERSION 3.5)
project(Glad)

add_compile_definitions(GLAD_GLAPI_EXPORT)
add_compile_definitions(GLAD_GLAPI_EXPORT_BUILD)

add_library(glad SHARED include/glad/glad.h src/glad.c)
target_include_directories(glad PUBLIC include/)