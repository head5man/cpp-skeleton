cmake_minimum_required(VERSION 3.5)

# A separate subdirectory for building Google Test so that C++ is not
# globally enabled

enable_language(CXX)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
  # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set (BUILD_SHARED_LIBS FALSE)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_MakeAvailable(googletest)
