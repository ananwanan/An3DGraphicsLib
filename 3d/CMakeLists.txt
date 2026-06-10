project(anan3d)

set(CMAKE_CXX_STANDARD 17)

add_library(anan3d SHARED
    src/common.cpp
    src/type_common.cpp
    src/matrix4.cpp
    src/matrix4_tool.cpp
    src/vector3.cpp
    src/vector3_tool.cpp
    src/point3.cpp
)

set_target_properties(anan3d PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(
    anan3d
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(
    anan3d
    PRIVATE AN3DGRAPHICSLIB_EXPORTS
)