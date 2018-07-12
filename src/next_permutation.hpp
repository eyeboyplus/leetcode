//
// Created by eyeboy on 2018/7/12.
//

#ifndef LEETCODE_NEXT_PERMUTATION_HPP
#define LEETCODE_NEXT_PERMUTATION_HPP

#include <vector>
#include <algorithm>

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 */
namespace next_permutation {

    using namespace std;

    void solution(vector<int> &nums) {
        int len = nums.size();

        int idx = len - 2;
        while(idx >= 0 && nums[idx] >= nums[idx+1]) idx --;

        if(idx == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = idx + 1;
        while(j < len && nums[j] > nums[idx]) ++j;

        // swap
        int temp = nums[idx];
        nums[idx] = nums[j - 1];
        nums[j - 1] = temp;

        // reverse
        for(int m = j, n = len - 1; m < n; ++m, --n) {
            int temp = nums[m];
            nums[m] = nums[n];
            nums[n] = temp;
        }
//        sort(nums.begin() + idx + 1, nums.end());
    }
}

#endif //LEETCODE_NEXT_PERMUTATION_HPP
