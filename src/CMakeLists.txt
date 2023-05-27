cmake_minimum_required(VERSION 3.3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Main source directory
include_directories(${CMAKE_CURRENT_LIST_DIR}/..)

# create custom target copying the logger configuration
# to the binary folder
set (conf_FILE log.conf)
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${conf_FILE}"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${conf_FILE}" "${CMAKE_CURRENT_BINARY_DIR}/${conf_FILE}"
    DEPENDS "${CMAKE_CURRENT_LIST_DIR}/${conf_FILE}"
)
add_custom_target(configuration ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/log.conf")

list(APPEND SourceFiles
    ${CMAKE_CURRENT_LIST_DIR}/Factory.cpp
)

list(APPEND TestFiles
    ${CMAKE_CURRENT_LIST_DIR}/../test/TestLogging.cpp
)

# skeleton main executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/main.cpp ${SourceFiles})
message(${log4cplus_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${log4cplus_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE log4cplus)

# skeleton sources as library
add_library(${PROJECT_NAME}-lib ${SourceFiles})
target_include_directories(${PROJECT_NAME}-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

# skeleton test executable
add_executable(${PROJECT_NAME}-test ${CMAKE_CURRENT_LIST_DIR}/../test/TestMain.cpp)
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}-lib gtest gmock_main)

add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
