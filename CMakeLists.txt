# CMakeList.txt : CMake project for Test-CPPLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.19)

project ("Test-CPPLib")
find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)

# _________________________ MAIN LIB TARGET_________________________
 
file(GLOB_RECURSE SOURCES_CPP "cpp/*.cpp")
file(GLOB_RECURSE SOURCES_H "headers/*.h")
add_compile_definitions(TESTMATH_DLLEXPORT)
add_library(Test-CPPLib SHARED ${SOURCES_H} ${SOURCES_CPP} )
target_include_directories(Test-CPPLib PUBLIC "headers")
set_property(TARGET Test-CPPLib PROPERTY CXX_STANDARD 20)

target_link_libraries(Test-CPPLib 
  PUBLIC
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts)
# _________________________ UNIT TESTS _________________________
enable_testing()
find_package(Catch2 REQUIRED)
find_package(Catch2 REQUIRED)
add_executable(UnitTests test.cpp)

target_link_libraries(UnitTests PUBLIC Test-CPPLib Catch2::Catch2WithMain)
target_include_directories(UnitTests PUBLIC "headers")

include(CTest)
include(Catch)
catch_discover_tests(UnitTests)