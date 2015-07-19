cmake_minimum_required(VERSION 2.8)
project(neocities-cpp CXX)

add_subdirectory(src)
add_subdirectory(opt/cpr)
include_directories(include/neoc)
include_directories(opt/cpr/include)

add_library(
  neocities-cpp
  STATIC
  ${neocities-cppSourceFiles}
)

target_link_libraries(
  neocities-cpp
  cpr
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(neocities-cpp-app src/main.cc)
target_link_libraries(neocities-cpp-app neocities-cpp)

#add_subdirectory(Tests)
#enable_testing()
#add_test(NAME Test COMMAND Test)

