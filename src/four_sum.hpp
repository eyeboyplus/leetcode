//
// Created by eyeboy on 2018/6/29.
//

#ifndef LEETCODE_FOUR_SUM_HPP
#define LEETCODE_FOUR_SUM_HPP

#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given an array nums of n integers and an integer target,
 * are there elements a, b, c, and d in nums such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
   Note:
    The solution set must not contain duplicate quadruplets.
   Example:
   Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
    A solution set is:
    [
        [-1,  0, 0, 1],
        [-2, -1, 1, 2],
        [-2,  0, 0, 2]
    ]
 */
namespace four_sum {
    vector<vector<int>> solution(vector<int> &nums, int target) {
        vector<vector<int>> result;

        int len = nums.size();

        if(len < 4)
            return result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int n1 = nums[i];
            for(int j = i+1; j < len; j ++) {
                if(j > i+1 && nums[j] == nums[j - 1])
                    continue;

                int n2 = nums[j];
                int start = j + 1;
                int end = len - 1;
                while(start < end) {
                    int n3 = nums[start];
                    int n4 = nums[end];

                    int val = n1 + n2 + n3 + n4;
                    if(val < target) {
                        while(++start < end && nums[start] == n3);
                    } else if(val > target) {
                        while(--end > start && nums[end] == n4);
                    } else {
                        vector<int> vec = {n1, n2, n3, n4};
                        result.push_back(vec);

                        while(++start < end && nums[start] == n3);
                    }
                }
            }
        }

        return result;
    }
}
#endif //LEETCODE_FOUR_SUM_HPP
