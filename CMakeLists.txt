cmake_minimum_required (VERSION 2.6)
project (Heron)

# The version number.
set (Heron_VERSION_MAJOR 1)
set (Heron_VERSION_MINOR 0)

# Let's tell it a bit about our environment
set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Modules that exist in both our release and our unit tests, are added now
  add_subdirectory(src)
