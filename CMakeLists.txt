cmake_minimum_required(VERSION 2.8)
project(foundation-wii)

find_package(WiiStep REQUIRED)

include_directories(Headers)
add_subdirectory(Source)

