//
// Created by eyeboy on 2018/7/14.
//

#ifndef LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
#define LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP

#include <vector>

/**
 *Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
 */
namespace search_in_rotated_sorted_array {

    using namespace std;

    int solution(vector<int> &nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }

    int solution_1(vector<int> &nums, int target) {
        int len = nums.size();

        if(len == 0)
            return -1;

        if(len == 1 && nums[0] == target)
            return 0;

        int head = nums[0];
        int tail = nums[len - 1];

        if(target > tail && target < head)
            return - 1;

        int i = 0, j = 0;
        if(target >= head) {
            i = 0;
            j = len - 1;
            while(j-1 >= 0 && nums[j] > nums[j - 1]) j --;
        }

        if(target <= tail) {
            i = 0;
            j = len - 1;
            while(i + 1 < len && nums[i] < nums[i+1]) i++;
        }

        while(i < j) {
            int center = (i + j) / 2;
            if(nums[center] == target)
                return center;
            else if(target < nums[center])
                j = center - 1;
            else
                i = center + 1;
        }
        return -1;
    }
}

#endif //LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
