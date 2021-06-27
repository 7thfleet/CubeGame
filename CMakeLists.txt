#=====Basic Setup=====
#Specify minimum CMake version
cmake_minimum_required(VERSION 3.14)

#Create a new project
project(CubeGame VERSION 1.0.0 
    DESCRIPTION "A simple CMake example project that computes the dot product of two vectors."
    LANGUAGES CXX
)

#Append modules folder to module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})


#=====Declare Targets=====
#Create the main library
add_library(CubeGame)

#Create the main executable
add_executable(CubeGame-bin)
#Change the executable output name (by default it would be CubeGame-bin)
set_target_properties(CubeGame-bin PROPERTIES OUTPUT_NAME CubeGame)



#=====Declare Dependencies=====
find_package(fmt REQUIRED)
find_package(Magnum REQUIRED GL Sdl2Application)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(MyApplication src/MyApplication.cpp)

if(APPLE)
    target_link_libraries(MyApplication PRIVATE
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
        "-framework CoreFoundation -framework Foundation -framework Cocoa -framework CoreServices -framework CoreAudio -framework CoreVideo -framework ForceFeedback -framework IOKit -framework Carbon -framework Metal -framework AudioToolbox"
    )
elseif()
    target_link_libraries(MyApplication PRIVATE
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
    )
endif()

#Make it a dependency of the executable, and the library.
target_link_libraries(CubeGame-bin PRIVATE fmt::fmt)
target_link_libraries(CubeGame PRIVATE fmt::fmt)

#Make CubeGame-bin (our driver) depend on our library (CubeGame)
target_link_libraries(CubeGame-bin PRIVATE CubeGame)



#=====Tweak build settings=====
#Set standard to C++14, require it, and turn off extensions (more portable code). Also make the directory structure more traditional (lib stuff in lib, execs in bin)
set_target_properties(CubeGame PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

set_target_properties(CubeGame-bin PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#If this project is being directly built (NOT as a dependency of another project)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    #Set the default build type to Debug
    #The `NOT CMAKE_CONFIGURATION_TYPES` makes the if statement only apply to single config generators (basically NOT visual studio and NOT xcode)
    if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "No build type set, defaulting to Debug")
        set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the build type." FORCE)
        #Set valid options
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif()

    #If testing wasn't explictly set, enable building it.
    if(NOT DEFINED BUILD_TESTING)
        message(STATUS "Enabling testing")
        set(BUILD_TESTING ON)
    endif()

    #Enable a bunch of warnings
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU") #Clang or GCC/G++
        set(compiler_warnings
            "-Wall;-Wextra;-Wshadow;-Wnon-virtual-dtor;-pedantic;-Wcast-align;-Wunused;-Woverloaded-virtual;-Wpedantic;-Wconversion")
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC") #Microsoft Visual Studio
        set(compiler_warnings "/permissive;/W4")
    endif()

    target_compile_options(CubeGame PRIVATE ${compiler_warnings})
    target_compile_options(CubeGame-bin PRIVATE ${compiler_warnings})
endif()


#Set the include directory for this library. PUBLIC means this directory is propagated to any targets that link to it.
target_include_directories(CubeGame
    PUBLIC include
    PRIVATE src/CubeGame #Sometimes you will have utility headers that aren't public, and shouldn't be distributed. These go in the src/CubeGame/ directory
)

#Add source directory
add_subdirectory(src)

#If this project is being directly built, and the tests are requested:
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    #Enable testing
    #Append the `--output-on-failure` argument to the ctest command. This makes the tests show output when they fail.
    list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
    include(CTest)
    add_subdirectory(tests)
endif()
