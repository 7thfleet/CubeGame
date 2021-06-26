<p align="center"><img width="45%" src="CoolLogo.png"></p>

# MathUtils [![Linux (GCC)](https://github.com/7thfleet/CubeGame/actions/workflows/linux.yml/badge.svg)](https://github.com/7thfleet/CubeGame/actions/workflows/linux.yml) [![Windows (MSVC)](https://github.com/7thfleet/CubeGame/actions/workflows/windows.yml/badge.svg)](https://github.com/7thfleet/CubeGame/actions/workflows/windows.yml) [![MacOS (AppleClang)](https://github.com/7thfleet/CubeGame/actions/workflows/macos.yml/badge.svg)](https://github.com/7thfleet/CubeGame/actions/workflows/macos.yml)

(@@TODO: A tldr of your project. Something like:)  
#### MathUtils is a cross platform @@TODO()-licensed C++14 application & library for generating the dot product of two `std::vector`s.

# Table of Contents
1. [Introduction](#introduction)
2. [Dependencies](#dependencies)
3. [Building & Testing](#building_testing)
    1. [On Boise State's R2](#building_testing_on_r2)
    2. [On a normal machine](#building_testing_on_a_normal_machine)
4. [Running](#running)
5. [Libraries Used](#libraries_used)
6. [License](#license)
7. [Contributors](#contributors)

<a name="introduction"></a>
# Introduction
(@@TODO A longer description of your awesome project!)
MathUtils is a simple library and application to show basic CMake functionality.  
This project uses the Pitchfork project layout.

<a name="dependencies"></a>
# Dependencies
* CMake 3.14 or newer
* A C++14 capable compiler
* An internet connection (some dependencies are fetched at build time via CMake's `FetchContent`)

<a name="building_testing"></a>
# Building & Testing
<a name="building_testing_on_r2"></a>
## On Boise State's R2
Load the required modules:  
```module load cmake gcc```  
Follow the steps for [on a normal machine](#building_testing_on_a_normal_machine)

<a name="building_testing_on_a_normal_machine"></a>
## On a normal machine
Note: Whenever `BUILD_TYPE` is used, replace with `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`.  
1. ### Clone the repository:   
```
git clone git@github.com:7thfleet/CubeGame.git
```

2. ### `cd` into the directory:  
```
cd CubeGame
```

3. ### Generate the build files:  
```
cmake -B build
```

   - The default build type is Debug. To change it for single-configuration generators (normally everything **but** Xcode and Visual Studio), append the following to the `cmake -S . -B build` command:  
``` -DCMAKE_BUILD_TYPE=BUILD_TYPE```  
     To disable building the tests, append ` -DBUILD_TESTING=OFF` to the `cmake -S . -B build` command.

4. ### Build the main executable/library:
```
cmake --build build
```  
   - For multi-configuration generators(normally **just** Xcode and Visual Studio), the build type can be selected by appending the following to the `cmake --build build` command:
```--config BUILD_TYPE```  

5. ### Running the tests:  
For single-configuration generators(normally everything but Xcode and Visual Studio):
```
cmake --build build -t test
```  
For multi-configuration generators(normally **only** Xcode and Visual Studio):
```
cmake --build build -t RUN_TESTS
```  
You may need to select the build type(for multi-configuration generators only). Append `--config BUILD_TYPE`. `BUILD_TYPE` should be the same as used in step #4.  
Note that the test target does not rebuild anything. As a result, you may want to run `cmake --build build` before running the tests after making changes.

<a name="running"></a>
# Running
After completing the [Building & Testing](#building_testing) steps, the binaries are located in `build/bin/`, and the library and archive files in `build/lib/`. Examples and documentation are provided below. Note if you are using a multi-configuration generator, they are located in `build/bin/BUILD_TYPE/`, and `build/lib/BUILD_TYPE`.
```
MathUtils <file1.txt> <file2.txt>
```
`file1.txt` and `file2.txt` must be ASCII text files representing the vectors to compute the dot product of. Each line must have one integer, and the files must be the same length(and therefore have the same number of integers). Two sample files are provided in `data/`. For example,
```
MathUtils data/one.txt data/two.txt
```
Will output `[1, 3, -5] DOT [4, -2, -1] = 3`

<a name="libraries_used"></a>
# Libraries Used
* [{fmt}](https://github.com/fmtlib/fmt)
* [doctest](https://github.com/onqtam/doctest/)

<a name="license"></a>
# License
The **code** in this repository, as well as the file `CoolLogo.png` are licensed under @@TODO. Note that any distributed binaries or build trees may require a different license, as the two libraries fetched at build time ({fmt} and doctest) are both MIT-licensed. See [LICENSE](LICENSE).
(@@TODO: The above is a bit more verbose than you need to be, since you'll likely be using a different license, like MIT).

<a name="contributors"></a>
# Contributors
* Add your name here!
* CMake Base Project: [Jared White](https://linkedin.com/in/jared7white)
