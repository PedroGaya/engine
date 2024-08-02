project(engine)

# glfw config

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glfw)

# libpng config

set(PNG_STATIC ON)
set(PNG_SHARED OFF)
set(PNG_TOOL OFF)
set(PNG_TESTS OFF)
set(SKIP_INSTALL_ALL OFF) 

add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/libpng)

# openal-soft config

set(ALSOFT_EXAMPLES OFF)
set(ALSOFT_UTILS OFF)

add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/openal)

# glad config

add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glad)

# glm config

set(glm_DIR ${PROJECT_SOURCE_DIR}/vendor/glm/cmake/glm)
find_package(glm REQUIRED)

# imgui config

add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/imgui)

# header only configuration

add_library(entt INTERFACE)
target_include_directories(entt INTERFACE ${PROJECT_SOURCE_DIR}/vendor/entt/include)

add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE ${PROJECT_SOURCE_DIR}/vendor/stb_image/include)

add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE ${PROJECT_SOURCE_DIR}/vendor/spdlog/include)

# linking

add_library(engine SHARED
    src/core/application.cpp
    src/core/input.cpp
    src/core/metrics.cpp
    src/core/logger/logger.cpp
    src/core/layer/layer.cpp
    src/core/layer/layer_stack.cpp
    src/core/imgui/imgui_layer.cpp
    src/core/imgui/debug_menu.cpp
    src/core/render/buffers.cpp
    src/core/render/vertex_array.cpp
    src/core/render/renderer.cpp
    src/core/render/shaders/shader.cpp
    src/core/window/window.cpp 
    # src/core/resource/resource_manager.cpp
    # src/core/resource/image.cpp
)
add_library(jc2d::engine ALIAS engine)

target_include_directories(engine PUBLIC 
    ${engine_SOURCE_DIR}/include
)
target_include_directories(engine PRIVATE
    ${engine_SOURCE_DIR}/vendor
)
target_precompile_headers(engine PRIVATE src/jc2dpch.h)

target_link_libraries(engine PUBLIC 
    glfw 
    png 
    OpenAL::OpenAL
    glad
    glm::glm
    entt
    stb_image
    spdlog
    imgui
) 