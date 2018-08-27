//
// Created by eyeboy on 2018/8/15.
//

#ifndef LEETCODE_MAXIMUM_SUBARRAY_HPP
#define LEETCODE_MAXIMUM_SUBARRAY_HPP

#include <vector>
#include <climits>

/**
 * Given an integer array nums,
 * find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    Example:
        Input: [-2,1,-3,4,-1,2,1,-5,4],
        Output: 6
        Explanation: [4,-1,2,1] has the largest sum = 6.
    Follow up:
    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
namespace maximum_subarray {
    using namespace std;
    int solution(vector<int> &nums) {
        int ret = INT_MIN;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            int res = nums[i];
            int max = res;
            for(int j = i + 1; j < len; ++j) {
                res += nums[j];
                if(res > max)
                    max = res;
            }
            if(max > ret)
                ret = max;
        }
        return ret;
    }
}

#endif //LEETCODE_MAXIMUM_SUBSTRING_HPP
