cmake_minimum_required(VERSION 3.15)

project(an_opengl LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------
# GLM (header-only)
# --------------------
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE
        ${CMAKE_SOURCE_DIR}/external/glm
)

# --------------------
# GLAD
# --------------------
add_library(glad STATIC
        external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
        external/glad/include
)

# --------------------
# GLFW
# --------------------
# find_package(glfw3 REQUIRED)
# find_package(glfw3 CONFIG REQUIRED)
add_subdirectory(external/glfw)

# --------------------
# Executable
# --------------------
add_library(an_opengl
        src/main.cpp
        src/shader.cpp
)

target_include_directories(
        an_opengl
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glad
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glm
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(an_opengl PUBLIC
        glfw
        glad
        glm
)

set_target_properties(an_opengl PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# --------------------
# Platform libs
# --------------------
if (UNIX AND NOT APPLE)
    target_link_libraries(an_opengl PRIVATE dl X11 pthread)
endif()

if (APPLE)
    find_library(COCOA Cocoa REQUIRED)
    find_library(OpenGL OpenGL REQUIRED)
    target_link_libraries(an_opengl PRIVATE ${COCOA} ${OpenGL})
endif()

add_custom_command(
    TARGET an_opengl POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/shaders
            $<TARGET_FILE_DIR:an_opengl>/shaders
)