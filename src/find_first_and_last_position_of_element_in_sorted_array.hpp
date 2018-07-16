//
// Created by eyeboy on 2018/7/15.
//

#ifndef LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP
#define LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP

#include <vector>

/**
 * Given an array of integers nums sorted in ascending order,
 * find the starting and ending position of a given target value.
    Your algorithm's runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return [-1, -1].
    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
 */
namespace find_first_and_last_position_of_element_in_sorted_array {

    using namespace std;

    int bin_search(vector<int> &nums, int start, int end,
                           int target, int mode) {
        int left = start, right = end;

        while(left <= right) {
            int mid = (left + right) / 2;
            int mid_val = nums[mid];

            if(target == mid_val) {
                if(mode) {  // left
                    if(mid - 1 >= left && nums[mid - 1] == target)
                        return bin_search(nums, left, mid - 1, target, 1);
                    else {
                        return mid;
                    }
                } else {    // right
                    if(mid + 1 <= right && nums[mid + 1] == target)
                        return bin_search(nums, mid + 1, right, target, 0);
                    else {
                        return mid;
                    }
                }
            } else if(target > mid_val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    vector<int> solution(vector<int> &nums, int target) {
        int lpos = bin_search(nums, 0, nums.size() - 1, target, 1);
        int rpos = bin_search(nums, 0, nums.size() - 1, target, 0);

        return vector<int>{lpos, rpos};
    }
}

#endif //LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_HPP
