cmake_minimum_required(VERSION 2.8)
project(foundation-wii)

find_package(WiiStep REQUIRED)

include_directories(Headers ../gnustep-make/TestFramework)
add_subdirectory(Source)

add_wii_executable(foundation-wii-test test.m)
target_link_wii_llvm_libraries(foundation-wii-test foundation-wii)
