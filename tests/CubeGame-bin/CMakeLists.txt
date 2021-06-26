#These tests directly run the driver executable. These type of tests are useful for testing command line arguments, calling external test scripts, and other forms of tests. For example, if your C++ project builds a python package, you might be able to call the python tests from here.

#We manually create the path to the executable since the target name and OUTPUT_NAME are no longer the same.
#CMake functions can't return a value, so the first argument is an output variable.
get_target_property(_test_with_args_runtime_directory CubeGame-bin RUNTIME_OUTPUT_DIRECTORY)
get_target_property(_test_with_args_output_name CubeGame-bin OUTPUT_NAME)
add_test(NAME CubeGame-bin_test COMMAND ${_test_with_args_runtime_directory}/${_test_with_args_output_name} ${CMAKE_SOURCE_DIR}/data/one.txt ${CMAKE_SOURCE_DIR}/data/two.txt)

#Escape the brackets
set_tests_properties(CubeGame-bin_test PROPERTIES PASS_REGULAR_EXPRESSION "\\[1, 3, -5\\] DOT \\[4, -2, -1\\] = 3")
