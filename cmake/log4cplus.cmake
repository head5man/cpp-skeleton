cmake_minimum_required(VERSION 3.5)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(log4cplus
  GIT_REPOSITORY    https://github.com/log4cplus/log4cplus.git
  GIT_TAG           2.1.x
  GIT_PROGRESS      TRUE
)

# TODO: Check does the linux build need this.
# macro(FetchContent_MakeAvailableWithConfigure NAME)
# 	FetchContent_GetProperties(${NAME})
# 	if(NOT ${NAME}_POPULATED)
# 		FetchContent_Populate(${NAME})
# 		add_custom_command (
# 			        OUTPUT ${${NAME}_SOURCE_DIR}/include/log4cplus/config/defines.hxx 
#                     COMMAND ${${NAME}_SOURCE_DIR}/configure 
#                     WORKING_DIRECTORY ${${NAME}_SOURCE_DIR}/)
# 		add_custom_target(${NAME}_configure ALL DEPENDS ${${NAME}_SOURCE_DIR}/include/log4cplus/config/defines.hxx)
# 		add_subdirectory(${${NAME}_SOURCE_DIR} ${${NAME}_BINARY_DIR})
# 	endif()
# endmacro()

FetchContent_MakeAvailable(log4cplus)
# if (UNICODE)
#   add_compile_definitions (UNICODE _UNICODE)
#   add_definitions (-UMBCS -U_MBCS)
# endif (UNICODE)

# add_compile_definitions (log4cplus_EXPORTS)
print_target_properties(log4cplus::log4cplus 
  LINK_LIBRARIES
  COMPILE_DEFINITIONS
  )