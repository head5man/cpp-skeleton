cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0077 NEW)

project(skeleton
    VERSION 0.1
    DESCRIPTION "skeleton c++ project template"
    LANGUAGES CXX
)

option(SKELETON_BUILD_TESTS "Build test program" ON)
option(SKELETON_BUILD_EXAMPLE "Build example" ON)

# Build without tchar = wchar_t
set(UNICODE OFF CACHE INTERNAL "" FORCE)

add_subdirectory(src)

if (SKELETON_BUILD_EXAMPLE)
  add_subdirectory(example)
endif (SKELETON_BUILD_EXAMPLE)

if (SKELETON_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif (SKELETON_BUILD_TESTS)