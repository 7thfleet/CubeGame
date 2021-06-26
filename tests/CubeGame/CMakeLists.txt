#Create a new target executable called CubeGame_test
add_executable(CubeGame_test CubeGame.test.cpp)

#Make it's binaries appear in the build/bin folder, for ease of use.
set_target_properties(CubeGame_test PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#Add one test file per source/header file below:
target_sources(CubeGame_test PRIVATE
    DotProduct.test.cpp
)

#Link it to the testing framework and main program library.
target_link_libraries(CubeGame_test doctest::doctest CubeGame)

#Register it wth CMake. If the target and the executable have the same name (which will be true unless it has been explicitly renamed, as we did with CubeGame-bin), COMMAND can just be the name of the target, as shown here.
add_test(NAME CubeGame_test COMMAND CubeGame_test)
