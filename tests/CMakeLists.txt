include(FetchContent)

#Find the doctest package
#find_package(doctest REQUIRED)

#Add our two test directories
add_subdirectory(CubeGame)

#@@TODO This directory tests directly invoking the executable with command line arguments. It is very possible that you don't need or want this functionality. If so, simply remove the below line and folder it references.
add_subdirectory(CubeGame-bin)
