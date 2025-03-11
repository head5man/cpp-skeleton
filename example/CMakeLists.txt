# cmake list called from root/CMakeLists.txt
# requires: skeleton-lib to be available
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common.cmake)

# TODO: relocate includes to appropriate folders
include_directories(${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_CURRENT_LIST_DIR}/../src)

# create custom target copying the logger configuration
# to the binary folder
set (LOG_CONF "log.conf")
if (MSVC)
  set (LOG_PFX "$<CONFIG>/")
endif()

set (TARGET_LOG_CONF "${LOG_PFX}${LOG_CONF}")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_LOG_CONF}"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${LOG_CONF}" "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_LOG_CONF}"
    DEPENDS "${CMAKE_CURRENT_LIST_DIR}/${LOG_CONF}"
)

add_custom_target(configuration ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_LOG_CONF}")

# skeleton example executable
add_executable(${PROJECT_NAME}-example ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
target_include_directories(${PROJECT_NAME}-example PUBLIC ${log4cplus_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}-example ${log4cplus} ${PROJECT_NAME}-lib)
if (MSVC)
  copy_target_runtime_dlls(${PROJECT_NAME}-example)
endif()
print_target_properties(${PROJECT_NAME}-example COMPILE_DEFINITIONS)

cmake_print_variables(CMAKE_CURRENT_BINARY_DIR LOG_CONF TARGET_LOG_CONF)

