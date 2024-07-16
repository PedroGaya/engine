cmake_minimum_required(VERSION 3.5)
project(imgui)


add_library(imgui STATIC 
    ${PROJECT_SOURCE_DIR}/imconfig.h
    ${PROJECT_SOURCE_DIR}/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/imgui_internal.h
    ${PROJECT_SOURCE_DIR}/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/imgui.cpp
    ${PROJECT_SOURCE_DIR}/imgui.h
    ${PROJECT_SOURCE_DIR}/imstb_rectpack.h
    ${PROJECT_SOURCE_DIR}/imstb_textedit.h
    ${PROJECT_SOURCE_DIR}/imstb_truetype.h

    ${PROJECT_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/backends/imgui_impl_glfw.h
    ${PROJECT_SOURCE_DIR}/backends/imgui_impl_opengl3_loader.h
    ${PROJECT_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/backends/imgui_impl_opengl3.h
)

target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(imgui PRIVATE glfw)