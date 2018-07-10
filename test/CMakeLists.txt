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
        letter_combinations_of_a_phone_number_test.cpp
        three_sum_test.cpp
        four_sum_test.cpp
        remove_n_th_node_from_end_of_list.cpp
        valid_parentheses_test.cpp
        merge_two_sorted_lists_test.cpp
        generate_parentheses_test.cpp
        merge_k_sorted_lists_test.cpp
        swap_nodes_in_pairs_test.cpp
        reverse_nodes_in_k_group_test.cpp
        remove_duplicates_from_sorted_array_test.cpp
        remove_element_test.cpp
        implement_str_str_test.cpp
        divide_two_integers_test.cpp
        )

target_link_libraries(runTests gtest gtest_main)