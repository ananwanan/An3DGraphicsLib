cmake_minimum_required(VERSION 3.10.0)
project(An3DGraphicsLib VERSION 0.1.0 LANGUAGES C CXX)

include_directories(3d/)

add_library(3d STATIC
        3d/src/matrix4.cpp
        3d/src/type_common.cpp
        3d/src/matrix4_tool.cpp)

add_executable(An3DGraphicsLib main.cpp)

target_compile_definitions(3d PRIVATE AN3DGRAPHICSLIB_EXPORTS)

target_link_libraries(An3DGraphicsLib PRIVATE 3d)