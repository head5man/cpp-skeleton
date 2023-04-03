cmake_minimum_required(VERSION 3.3.2)

# A separate subdirectory for building Google Test so that C++ is not
# globally enabled

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

# should be and seems to work fine on stock ubuntu 
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
