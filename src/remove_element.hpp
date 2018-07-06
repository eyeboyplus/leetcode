//
// Created by eyeboy on 2018/7/6.
//

#ifndef LEETCODE_REMOVE_ELEMENT_HPP
#define LEETCODE_REMOVE_ELEMENT_HPP

#include <vector>

/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
namespace remove_element {
    using namespace std;

    int solution(vector<int> &nums, int val) {
        int len = nums.size();

        int j = 0;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == val)
                continue;
            else
                nums[j++] = nums[i];
        }

        return j;
    }
}

#endif //LEETCODE_REMOVE_ELEMENT_HPP
