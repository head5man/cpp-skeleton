cmake_minimum_required(VERSION 3.3.2)

project(skeleton
    VERSION 0.1
    DESCRIPTION "skeleton c++ project template"
    LANGUAGES CXX
)

include(CTest)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_TAG             release-1.10.0
                 GIT_REPOSITORY 	    https://github.com/google/googletest
                 PREFIX              .cmakeDownload
                 BINARY_DIR          ${CMAKE_BINARY_DIR}/googletest-build
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(src)
