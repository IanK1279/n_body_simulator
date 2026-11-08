cmake_minimum_required(VERSION 3.14)
project(n_body_simulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Library: everything except main()
add_library(nbody_lib
  src/forces.cpp
  src/integrators.cpp
  src/diagnostics.cpp)
target_include_directories(nbody_lib PUBLIC include)
target_compile_options(nbody_lib PRIVATE -Wall -Wextra)

# Simulation executable
add_executable(nbody src/main.cpp)
target_link_libraries(nbody PRIVATE nbody_lib)

# Tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(nbody_tests tests/test_nbody.cpp)
target_link_libraries(nbody_tests PRIVATE nbody_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(nbody_tests)