# Set target name.
set(LIB_NAME "game-components")

# Define list of source files.
list(
    APPEND
    SOURCE_FILES
    "bullet.cpp"
    "entity.cpp"
    "game.cpp"
    "game-map.cpp"
    "input-handler.cpp"
    "player.cpp"
    "world.cpp"
)

# Create library.
add_library(${LIB_NAME} STATIC ${SOURCE_FILES})

# Specify include directories to use when compiling a given target.
target_include_directories(${LIB_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

# Set compiler warnings.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
        ${LIB_NAME}
        PUBLIC
        "-Wall;-Wextra;-Wno-switch"
    )
endif()
