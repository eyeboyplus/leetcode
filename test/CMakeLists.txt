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
        substring_with_concatenation_of_all_words_test.cpp
        next_permutation_test.cpp
        longest_valid_parentheses_test.cpp
        search_in_rotated_sorted_array_test.cpp
        find_first_and_last_position_of_element_in_sorted_array_test.cpp
        search_insert_position_test.cpp
        valid_sudoku_test.cpp
        sudoku_solver_test.cpp
        count_and_say_test.cpp
        combination_sum_test.cpp
        combination_sum_ii_test.cpp
        first_missing_positive_test.cpp
        n_queens_test.cpp
        n_queens_ii_test.cpp
        maximum_subarray_test.cpp
        trapping_rain_water_test.cpp
        multiply_strings_test.cpp
        jump_game_ii_test.cpp
        permutations_test.cpp
        permutations_ii_test.cpp
        rotate_image_test.cpp
        group_anagrams_test.cpp
        pow_x_n_test.cpp
        jump_game_test.cpp
        merge_intervals_test.cpp
        insert_interval_test.cpp
        length_of_last_word_test.cpp
        sort/quick_sort_test.cpp
        spiral_matrix_ii_test.cpp
        )

target_link_libraries(runTests gtest gtest_main)