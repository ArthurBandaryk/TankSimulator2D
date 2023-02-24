# Set cmake minimum version.
cmake_minimum_required(VERSION 3.25.1)

# Set project name.
project(Tank2D)

# Set cpp standart.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create executable from source.
add_executable(game main.cpp)
