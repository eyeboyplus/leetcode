//
// Created by eyeboy on 2018/6/28.
//

#ifndef LEETCODE_THREE_SUM_CLOSEST_HPP
#define LEETCODE_THREE_SUM_CLOSEST_HPP

#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Given an array nums of n integers and an integer target,
 * find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
Example:
    Given array nums = [-1, 2, 1, -4], and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
 namespace three_sum_closest {
     // brute force
     // O(n^3),O(1)
     int solution_1(vector<int> &nums, int target) {
         int len = nums.size();

         int diff = INT_MAX;
         int result = 0;
         for(int i = 0; i < len; ++i) {
             for(int j = i + 1; j < len; ++j) {
                 for(int k = j + 1; k < len; ++k) {

                     int n1 = nums[i];
                     int n2 = nums[j];
                     int n3 = nums[k];

                     int val = n1 + n2 + n3;
                     int d = abs(val - target);
                     if(diff > d) {
                         diff = d;
                         result = val;
                     }
                 }
             }
         }
         return result;
     }

     int solution_2(vector<int> &nums, int target) {
         sort(nums.begin(), nums.end());

         int result = INT_MAX;

         int len = nums.size();
         for(int i = 0; i < len; ++i) {
             int head = i + 1, tail = len - 1;
             while(head < tail) {
                 int val = nums[i] + nums[head] + nums[tail];
                 if(abs(result - target) > abs(val - target))
                     result = val;

                 if(result < target)
                     head ++;
                 else
                     tail --;
             }
         }
         return result;
     }
 }

#endif //LEETCODE_THREE_SUM_CLOSEST_HPP
