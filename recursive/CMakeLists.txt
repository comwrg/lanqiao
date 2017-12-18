cmake_minimum_required(VERSION 3.9)
project(resursive)

set(CMAKE_CXX_STANDARD 11)

add_executable(resursive_search resursive_search.cpp)
add_executable(binary_search binary_search.cpp)
add_executable(merge_sort merge_sort.cpp)
add_executable(quick_sort quick_sort.cpp)