include(CTest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/googletest.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

list(APPEND TestFiles
    ${CMAKE_CURRENT_LIST_DIR}/TestMain.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/LoggerTest.cpp
)

add_executable(${PROJECT_NAME}-test ${TestFiles})

target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}-lib gtest gmock gmock_main)

target_include_directories(${PROJECT_NAME}-test PUBLIC ${log4cplus_SOURCE_DIR}/include)

add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)

print_target_properties(${PROJECT_NAME}-test LINK_LIBRARIES)