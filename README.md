# neocities-cpp
A C++ wrapper for the Neocities API.

# Setup
```Shell
$ git clone --recursive https://github.com/matthin/neocities-cpp.git
$ cd neocities-cpp
$ mkdir build && cd build
$ cmake ..
$ make
```

# Usage
Assuming you're using CMake, and neocities-cpp is located at 'opt/neoc'.

```CMake
add_subdirectory(opt/neoc)
include_directories(opt/neoc/include)
target_link_libraries(YOUR_EXECUTABLE neocities-cpp)
```

