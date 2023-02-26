# Set cmake minimum version.
cmake_minimum_required(VERSION 3.25.1)

# Set project name.
project(Tank2D)

# Set cpp standart.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set target name.
set(TARGET_NAME "game")

# Find sfml package.
find_package(
    SFML
    COMPONENTS graphics system
    REQUIRED
)

# Add src subdirectory.
add_subdirectory(src)

# Create executable.
add_executable(${TARGET_NAME} "src/main.cpp")

# Specify libraries when linking a given target.
target_link_libraries(${TARGET_NAME} PUBLIC tank sfml-graphics)

# Set compiler warnings.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
        ${TARGET_NAME}
        PUBLIC
        "-Wall;-Wextra;"
    )
endif()
