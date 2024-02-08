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

# linking

add_library(engine SHARED 
    src/core/logger.cpp 
)
add_library(jc2d::engine ALIAS engine)

target_include_directories(engine PUBLIC 
    ${engine_SOURCE_DIR}/include
)
target_include_directories(engine PRIVATE 
    ${PROJECT_SOURCE_DIR}/vendor
)

target_link_libraries(engine PUBLIC 
    glfw 
    png 
    openal
    glad
    glm::glm
) 