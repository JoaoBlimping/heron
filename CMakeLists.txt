project ("Heron" C)
cmake_minimum_required (VERSION 3.0)

# The version number.
set (Heron_VERSION_MAJOR 1)
set (Heron_VERSION_MINOR 0)

# Let's tell it a bit about our environment
set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# add the source files folder
add_subdirectory(src)
