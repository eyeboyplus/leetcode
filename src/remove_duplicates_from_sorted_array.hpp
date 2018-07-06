//
// Created by eyeboy on 2018/7/6.
//

#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP

#include <vector>

/**
 * Given a sorted array nums, remove the duplicates in-place
 * such that each element appear only once and return the new length.
 * Do not allocate extra space for another array,
 * you must do this by modifying the input array in-place with O(1) extra memory.
 */
namespace remove_duplicates_from_sorted_array {

    using namespace std;

    int solution(vector<int> &nums) {
        if(nums.empty())
            return 0;

        int j = 1;
        int len = nums.size();

        for(int i = 0; i < len; ++i) {
            if(nums[j - 1] == nums[i]) {
                continue;
            } else {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
}

#endif //LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
