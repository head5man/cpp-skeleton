cmake_minimum_required(VERSION 3.5)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
set(LOG4CPLUS_BUILD_TESTING OFF CACHE INTERNAL "" FORCE)

include(FetchContent)

FetchContent_Declare(log4cplus
  GIT_REPOSITORY    https://github.com/log4cplus/log4cplus.git
  GIT_TAG           2.1.x
  GIT_PROGRESS      TRUE
)

FetchContent_MakeAvailable(log4cplus)

print_target_properties(log4cplus::log4cplus 
  LINK_LIBRARIES
  COMPILE_DEFINITIONS
  )