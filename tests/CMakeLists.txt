include(FetchContent)

#Fetch the testing framework from github
message(STATUS "Fetching content: doctest")
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    GIT_TAG 2.4.6
)

FetchContent_MakeAvailable(doctest)
message(STATUS "doctest successfully fetched.")


#Add our two test directories
add_subdirectory(CubeGame)

#@@TODO This directory tests directly invoking the executable with command line arguments. It is very possible that you don't need or want this functionality. If so, simply remove the below line and folder it references.
add_subdirectory(CubeGame-bin)
