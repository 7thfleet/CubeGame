//This #define tells the testing framework to create the main function. We only want one main per testing executable, so we make it here in a stand-alone file. All of the tests in this suite will then link to it (via target_sources in the CMakeLists.txt file)
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
