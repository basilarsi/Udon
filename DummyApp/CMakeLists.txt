add_executable(DummyApp src/main.cpp)

target_link_libraries(DummyApp PRIVATE Udon)

add_custom_command(TARGET DummyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Udon>
    $<TARGET_FILE_DIR:DummyApp>
    COMMENT "Copying libUdon.dll to the build directory")

add_custom_command(TARGET DummyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3>
    $<TARGET_FILE_DIR:DummyApp>
    COMMENT "Copying SDL3.dll to the build directory")

if(MINGW)
  get_filename_component(MINGW_BIN_DIR ${CMAKE_CXX_COMPILER} PATH)
  add_custom_command(TARGET DummyApp POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${MINGW_BIN_DIR}/libstdc++-6.dll"
      $<TARGET_FILE_DIR:DummyApp>
      COMMENT "Copying libstdc++-6.dll to the build directory")

  add_custom_command(TARGET DummyApp POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${MINGW_BIN_DIR}/libgcc_s_seh-1.dll"
      $<TARGET_FILE_DIR:DummyApp>
      COMMENT "Copying libgcc_s_seh-1.dll to the build directory")

  add_custom_command(TARGET DummyApp POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${MINGW_BIN_DIR}/libwinpthread-1.dll"
      $<TARGET_FILE_DIR:DummyApp>
      COMMENT "Copying libwinpthread-1.dll to the build directory")
endif()