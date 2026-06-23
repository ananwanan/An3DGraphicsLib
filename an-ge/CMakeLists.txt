project(an-ge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(an-ge SHARED
        src/type_common.cpp
        src/matrix4.cpp
        src/matrix4_tool.cpp
        src/vector3.cpp
        src/vector3_tool.cpp
        src/point3.cpp
        src/an_math.cpp)

set_target_properties(an-ge PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(
        an-ge
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(
        an-ge
        PRIVATE AN3DGRAPHICSLIB_EXPORTS
)
