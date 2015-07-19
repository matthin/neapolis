cmake_minimum_required(VERSION 2.8)
project(neapolis CXX)

add_subdirectory(src)
add_subdirectory(opt/cpr)
include_directories(include/neapolis)
include_directories(opt/cpr/include)

add_library(
  neapolis
  STATIC
  ${neapolisSourceFiles}
)

target_link_libraries(
  neapolis
  cpr
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(neapolisApp src/main.cc)
target_link_libraries(neapolisApp neapolis)

#add_subdirectory(Tests)
#enable_testing()
#add_test(NAME Test COMMAND Test)

