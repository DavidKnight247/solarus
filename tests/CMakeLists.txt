# Build the Solarus testing library.
file(
  GLOB
  testing_source_files
  src/test_tools/*.cpp
  include/test_tools/*.h
  include/test_tools/*.inl
)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_library(solarus_testing
  STATIC
  ${testing_source_files}
)

# Build individual tests.

# Each .cpp file of the 'src/tests' directory is a test with a main() function
file(
  GLOB
  tests_main_files
  src/tests/*.cpp
)

foreach(test_main_file ${tests_main_files})

  get_filename_component(test_bin_file ${test_main_file} NAME_WE)
  add_executable(${test_bin_file} ${test_main_file})

  target_link_libraries(${test_bin_file}
    solarus_static
    solarus_testing
    "${SDL2_LIBRARY}"
    "${SDL2_IMAGE_LIBRARY}"
    "${SDL2_TTF_LIBRARY}"
    "${OPENAL_LIBRARY}"
    "${LUA_LIBRARY}"
    "${DL_LIBRARY}"
    "${PHYSFS_LIBRARY}"
    "${VORBISFILE_LIBRARY}"
    "${OGG_LIBRARY}"
    "${MODPLUG_LIBRARY}"
  )
  set_target_properties(${test_bin_file}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
)

add_test(${test_main_file} "bin/${test_bin_file}" -no-audio -no-video ${SOLARUS_CURRENT_SOURCE_DIR}/testing_quest)

endforeach(test_main_file ${test_main_files})
