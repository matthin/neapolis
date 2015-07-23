# neapolis
[![Build Status](https://travis-ci.org/matthin/neapolis.png?branch=master)]
(https://travis-ci.org/matthin/neapolis)

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

##### State of Unit Testing

I can't fully wrap my head around mocking objects in C++. I come from a Ruby
background where everything can be easily modified at runtime, which is a huge
difference compared to C++.

I've looked into Google Mock and a few different mocking frameworks, but I
don't like the idea of leaking testing implementation details into the real
objects, such as needing to declare every mocked method as `virtual`. I'm
probably forced into doing so, but I first want to to spend quite a while
researching the most modern mocking pattern.

If anyone else wants to take a shot at mocking the Client object to not hit the
remote API, I'll gladly welcome it.

