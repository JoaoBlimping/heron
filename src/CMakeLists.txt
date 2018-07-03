# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/HeronConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/HeronConfig.h"
  )



# add the binary tree to the search path for include files so that we will find HeronConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/src")


# add the install targets
add_executable(heron shell.c)
install (TARGETS heron DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/src/HeronConfig.h"
         DESTINATION include)
