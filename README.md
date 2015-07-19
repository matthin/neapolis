# neapolis
A C++ wrapper for the Neocities API.

# Usage
Assuming you're using CMake, and want neapolis to be at 'opt/neapolis'.

### Installation
```Shell
$ git clone --recursive https://github.com/matthin/neapolis.git opt/neapolis
```

##### CMakeLists.txt
```CMake
add_subdirectory(opt/neapolis)
include_directories(opt/neoc/neapolis)
target_link_libraries(YOUR_EXECUTABLE neapolis)
```

# Contributors
### Setup
```Shell
$ git clone --recursive https://github.com/matthin/neapolis.git
$ cd neapolis
$ mkdir build && cd build
$ cmake ..
$ make
```

