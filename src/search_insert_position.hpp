//
// Created by eyeboy on 2018/7/16.
//

#ifndef LEETCODE_SEARCH_INSERT_POSITION_HPP
#define LEETCODE_SEARCH_INSERT_POSITION_HPP

#include <vector>

/**
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */
namespace search_insert_position {

    using namespace std;

    int solution_1(vector<int> &nums, int target) {
        int len = nums.size();

        for(int i = 0; i < len; ++i) {
            if(target <= nums[i])
                return i;
        }
        return len;
    }

    int solution(vector<int> &nums, int target) {
        int len = nums.size();

        if(nums.empty())
            return 0;

        int left = 0, right = len - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

#endif //LEETCODE_SEARCH_INSERT_POSITION_HPP
