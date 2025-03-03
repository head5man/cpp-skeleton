cmake_minimum_required(VERSION 3.3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Main source directory
include_directories(${CMAKE_CURRENT_LIST_DIR}/.. )

file(GLOB TestFiles "${CMAKE_CURRENT_SOURCE_DIR}/*Test.cpp")

# skeleton test executable
add_executable(${PROJECT_NAME}-test ${CMAKE_CURRENT_SOURCE_DIR}/TestMain.cpp ${TestFiles})
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}-lib gtest gmock_main messages)
target_include_directories(${PROJECT_NAME}-test PRIVATE ${log4cplus_SOURCE_DIR}/include ${protobuf_SOURCE_DIR}/google)

add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)

#install(TARGETS ${PROJECT_NAME}-test RUNTIME DESTINATION ${CMAKE_ROOT})