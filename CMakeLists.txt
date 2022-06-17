# CMakeList.txt : CMake project for Test-CPPLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.19)

project ("Test-CPPLib")
find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)

# _________________________ MAIN LIB TARGET_________________________
 
file(GLOB_RECURSE SOURCES_CPP "src/*.cpp")
file(GLOB_RECURSE SOURCES_H "include/*.h")
add_compile_definitions(TESTMATH_DLLEXPORT)
add_library(Test-CPPLib SHARED ${SOURCES_H} ${SOURCES_CPP} )
target_include_directories(Test-CPPLib PUBLIC "include")
set_property(TARGET Test-CPPLib PROPERTY CXX_STANDARD 20)

target_link_libraries(Test-CPPLib 
  PUBLIC
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts)
# _________________________ UNIT TESTS _________________________

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)
file(GLOB_RECURSE TEST_CPP "tests/src/*.cpp")
file(GLOB_RECURSE TEST_H "tests/include/*.h")

add_executable(UnitTests ${TEST_H} ${TEST_CPP} )

target_link_libraries(UnitTests PUBLIC Test-CPPLib GTest::GTest GTest::Main)
target_include_directories(UnitTests PUBLIC "include")

gtest_discover_tests(UnitTests)