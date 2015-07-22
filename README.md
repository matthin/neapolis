# neapolis
A C++ wrapper for the Neocities API.

# Requirements
* libcurl (sudo apt-get install libcurl4-openssl-dev)
* C++11 campatible compiler
* CMake v2.8.7+
* Git v1.6.5+

# Usage
Assuming you're using CMake, and want neapolis to be at 'opt/neapolis'.

### Installation
```Shell
$ git clone --recursive https://github.com/matthin/neapolis.git opt/neapolis
```

### CMakeLists.txt
```CMake
add_subdirectory(opt/neapolis)
include_directories(opt/neapolis/include)
target_link_libraries(YOUR_EXECUTABLE neapolis)
```

### Example
```C++
nea::Client client("user", "pass");
std::cout << client.upload({
  {"test.html", "path/to/test.html"}
}).successful() << std::endl;
std::cout << client.info("some_user").successful() << std::endl;
std::cout << client.remove("test.html").successful() << std::endl;
```

# Contributors
### Setup
```Shell
$ git clone --recursive https://github.com/matthin/neapolis.git
$ cd neapolis
$ mkdir build && cd build
$ cmake -DUSE_SYSTEM_CURL=ON ..
$ make
```

