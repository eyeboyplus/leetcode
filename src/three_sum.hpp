//
// Created by eyeboy on 2018/6/29.
//
#ifndef LEETCODE_THREE_SUM_HPP
#define LEETCODE_THREE_SUM_HPP

#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
   Note:
    The solution set must not contain duplicate triplets.
  Example:
    Given array nums = [-1, 0, 1, 2, -1, -4],
    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
 */
 // O(n^2), O(1)
namespace three_sum {
    vector<vector<int>> solution(vector<int> &nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int len = nums.size();

        if(len < 3)
            return result;

        for(int i = 0; i < len; ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int start = i + 1;
            int end = len - 1;
            int n1 = nums[i];
            while(start < end) {
                int n2 = nums[start];
                int n3 = nums[end];
                int val = n1 + n2 + n3;

                if(val > target) {
                    while((--end) > start && nums[end] == n3);
                } else if(val < target) {
                    while((++start) < len && nums[start] == n2);
                } else {
                    vector<int> vec = {n1, n2, n3};
                    result.push_back(vec);

                    while((++start) < len && nums[start] == n2);
                };
            }
        }

        return result;
    }
}

#endif //LEETCODE_THREE_SUM_HPP
