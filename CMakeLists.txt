cmake_minimum_required(VERSION 3.10)
project(ccgl C)

set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)
include_directories(include include/glad)

# Add GLAD sources
set(GLAD_SOURCES src/glad/glad.c)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()
# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

# Use PkgConfig to find GLFW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})

# Debug messages
message(STATUS "GLFW include dirs: ${GLFW_INCLUDE_DIRS}")
message(STATUS "GLFW libraries: ${GLFW_LIBRARIES}")

# Source files
file(GLOB CCGL_SOURCES
    src/core/*.c
    src/window/*.c
    src/log/*.c
)

# Build the ccgl library
add_library(ccgl STATIC ${CCGL_SOURCES} ${GLAD_SOURCES})

# Link libraries
target_link_libraries(ccgl ${GLFW_LIBRARIES} ${OPENGL_gl_LIBRARIES})

# Build examples
add_executable(example examples/main.c)
target_link_libraries(example ccgl ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${CMAKE_DL_LIBS})

