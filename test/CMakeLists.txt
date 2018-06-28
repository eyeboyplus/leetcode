cmake_minimum_required(VERSION 3.9)

project(test)

add_subdirectory(gtest)

include_directories(gtest/googletest/include)
include_directories(gtest/googlemock/include)
include_directories(./../src)

add_executable(runTests
        gtest_main.cpp
        wildcard_matching_test.cpp
        binary_tree_inorder_traverse_test.cpp
        regular_expression_matching_test.cpp
        container_with_most_water_test.cpp
        integer_to_roman_test.cpp
        roman_to_integer_test.cpp
        longest_common_prefix_test.cpp
        three_sum_closest_test.cpp
        )

target_link_libraries(runTests gtest gtest_main)