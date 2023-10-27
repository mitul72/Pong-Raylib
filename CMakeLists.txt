cmake_minimum_required(VERSION 3.22)
project(raylib_main)

set(CMAKE_CXX_STANDARD 20)

# Add raylib as a dependency
add_subdirectory(deps/raylib)

# Get all the C++ files in src
file(GLOB_RECURSE RAYLIB_SOURCES
    src/*.cpp
)
add_executable(raylib_main ${RAYLIB_SOURCES})
target_include_directories(raylib_main PRIVATE
        src/
)
target_include_directories(${PROJECT_NAME} PRIVATE deps/raylib/src)

target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
)

