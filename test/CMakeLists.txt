cmake_minimum_required(VERSION 3.9)

project(test)

add_subdirectory(gtest)

include_directories(gtest/googletest/include)
include_directories(gtest/googlemock/include)
include_directories(./../src)

add_executable(runTests gtest_main.cpp ../src/binary_tree_inorder_traverse.hpp binary_tree_inorder_traverse_test.cpp ../src/regular_expression_matching.hpp regular_expression_matching_test.cpp " wildcard_matching_test.cpp" ../src/container_with_most_water.hpp container_with_most_water_test.cpp integer_to_roman_test.cpp)

target_link_libraries(runTests gtest gtest_main)