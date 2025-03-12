include(CMakePrintHelpers)

macro (print_target_properties NAME)
  cmake_print_properties(
    TARGETS ${NAME}
    PROPERTIES ${ARGN}
  )
endmacro()

macro(copy_target_runtime_dlls NAME)
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${NAME}> $<TARGET_FILE_DIR:${NAME}>
    COMMAND_EXPAND_LISTS
  )
endmacro()

macro(silence_msvc_warnings NAME)
  target_compile_definitions(${NAME} PRIVATE "" _CRT_SECURE_NO_WARNINGS)
endmacro()