cmake_minimum_required(VERSION 3.15)

project(an_opengl LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==================================================
# GLM (Header Only)
# ==================================================
add_library(glm INTERFACE)

target_include_directories(glm INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glm
)

# ==================================================
# GLAD
# ==================================================
add_library(glad STATIC
        external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/external
)

# ==================================================
# GLFW
# ==================================================
add_subdirectory(external/glfw)

# ==================================================
# an_opengl Library
# ==================================================
add_library(an_opengl STATIC
        src/shader.cpp
)

target_include_directories(an_opengl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(an_opengl PUBLIC
        glfw
        glad
        glm
)

set_target_properties(an_opengl PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ==================================================
# Demo
# ==================================================
add_executable(an_opengl_demo
        src/main.cpp
)

target_link_libraries(an_opengl_demo PRIVATE
        an_opengl
)

set_target_properties(an_opengl_demo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ==================================================
# Linux
# ==================================================
if(UNIX AND NOT APPLE)
    target_link_libraries(an_opengl_demo PRIVATE
            dl
            X11
            pthread
    )
endif()

# ==================================================
# macOS
# ==================================================
if(APPLE)
    find_library(COCOA Cocoa REQUIRED)
    find_library(OpenGL OpenGL REQUIRED)

    target_link_libraries(an_opengl_demo PRIVATE
            ${COCOA}
            ${OpenGL}
    )
endif()

# ==================================================
# Copy shaders after build
# ==================================================
add_custom_command(
        TARGET an_opengl_demo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/shaders
        $<TARGET_FILE_DIR:an_opengl_demo>/shaders
)