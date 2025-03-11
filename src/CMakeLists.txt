cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/log4cplus.cmake)

list(APPEND SourceFiles
    ${CMAKE_CURRENT_LIST_DIR}/Factory.cpp
)

# skeleton sources as library
add_library(${PROJECT_NAME}-lib STATIC ${SourceFiles})

if (MSVC)
    target_compile_definitions(${PROJECT_NAME}-lib PRIVATE "" _CRT_SECURE_NO_WARNINGS)
endif()

target_include_directories(${PROJECT_NAME}-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/.. ${log4cplus_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}-lib log4cplus::log4cplus)
print_target_properties(${PROJECT_NAME}-lib COMPILE_DEFINITIONS)
