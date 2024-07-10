add_executable (DeepRunner "DeepRunner.cpp" "DeepRunner.h" )

target_link_libraries(DeepRunner PRIVATE Nan)

# Copy dll to excutable folder
add_custom_command(TARGET DeepRunner POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:DeepRunner> $<TARGET_FILE_DIR:DeepRunner>
  COMMAND_EXPAND_LISTS
  )
