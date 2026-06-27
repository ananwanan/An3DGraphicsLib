cmake_minimum_required(VERSION 3.10)

project(an3d VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(an-ge)
add_subdirectory(an-opengl)

add_executable(an3d
        src/main.cpp
)

set_target_properties(an3d PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_link_libraries(an3d
        PRIVATE
        an_ge an_opengl
)
