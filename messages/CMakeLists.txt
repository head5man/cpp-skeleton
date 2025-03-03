# Requires Protobuf package
# ubuntu:
# apt-get install protobuf-compiler
find_package(Protobuf REQUIRED)
file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
file(GLOB MessagesSourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(... PARENT_SCOPE)
PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
message(STATUS "Generated sources: ${ProtoSources}")
message(STATUS "Generated headers: ${ProtoHeaders}")
message(STATUS "protobuf source: ${protobuf_SOURCE_DIR}/src")
add_library(messages STATIC ${MessagesSourceFiles} ${ProtoSources} ${ProtoHeaders})
target_include_directories(messages PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${protobuf_SOURCE_DIR}/src)
target_link_libraries(messages ${PROTOBUF_LIBRARY})
#add_library(messages STATIC ${ProtoSources} ${ProtoHeaders})
#target_link_libraries(messages ${PROTOBUF_LIBRARY})