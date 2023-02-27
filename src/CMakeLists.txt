# Set target name.
set(LIB_NAME "game-components")

# Define list of source files.
list(
    APPEND
    SOURCE_FILES
    "entity.cpp"
    "game.cpp"
    "world.cpp"
)

# Create library.
add_library(${LIB_NAME} STATIC ${SOURCE_FILES})

# Specify include directories to use when compiling a given target.
target_include_directories(${LIB_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)
