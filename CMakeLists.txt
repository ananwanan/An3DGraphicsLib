cmake_minimum_required(VERSION 3.10)

project(An3DGraphicsLib VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(3d)
add_subdirectory(an-opengl)

add_executable(An3DGraphicsLib
        main.cpp
)

set_target_properties(An3DGraphicsLib PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_link_libraries(An3DGraphicsLib
        PRIVATE
        anan3d an_opengl
)
