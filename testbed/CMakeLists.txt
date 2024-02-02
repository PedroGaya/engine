project(testbed)

# linking

add_executable(testbed 
    ./src/main.cpp 
)

target_include_directories(testbed PUBLIC ${engine_SOURCE_DIR}/include)

target_link_libraries(testbed
    jc2d::engine
) 