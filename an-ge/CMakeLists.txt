project(an-ge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(SOURCES
#        include/type_common.h
#        src/type_common.cpp
#        include/matrix4.h
#        src/matrix4.cpp
#        src/matrix4_tool.cpp
#        include/vector3.h
#        src/vector3.cpp
#        src/vector3_tool.cpp
#        include/point3.h
#        src/point3.cpp
#        include/an_math.h
#        src/an_math.cpp
#        include/string_tool.h
#        src/string_tool.cpp
#)
#add_library(an-ge SHARED ${SOURCES})
#target_sources(an-ge PRIVATE ${SOURCES})

file(GLOB_RECURSE INC_FILES "include/*.h" "include/*.inl")
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_library(an-ge SHARED ${INC_FILES} ${SRC_FILES})

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

