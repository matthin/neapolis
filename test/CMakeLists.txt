set(testSourceFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/Client.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
)

include_directories(.)

add_executable(neapolisTest ${testSourceFiles})
target_link_libraries(
  neapolisTest
  neapolis
)

