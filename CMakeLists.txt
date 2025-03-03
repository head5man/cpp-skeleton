cmake_minimum_required(VERSION 3.3.2)

project(skeleton
    VERSION 0.1
    DESCRIPTION "skeleton c++ project template"
    LANGUAGES CXX
)

include(CTest)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_Declare(
  protobuf
  URL https://github.com/protocolbuffers/protobuf/archive/66dc42d891a4fc8e9190c524fd67961688a37bbe.zip
  #GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  #GIT_TAG a20c65f2cd549445fda907f7b83894c8eb7427d6 #v3.6.1.3
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest protobuf)

#include(DownloadProject.cmake)
#download_project(PROJ                googletest
#                 GIT_TAG             release-1.10.0
#                 GIT_REPOSITORY 	    https://github.com/google/googletest
#                 PREFIX              .cmakeDownload
#                 BINARY_DIR          ${CMAKE_BINARY_DIR}/googletest-build
#                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
#)

#find_package(protobuf REQUIRED)

add_subdirectory(messages)
add_subdirectory(log4cplus)
add_subdirectory(src)
add_subdirectory(test)
