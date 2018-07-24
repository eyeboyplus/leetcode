//
// Created by eyeboy on 2018/7/24.
//
#ifndef FIRST_MISSING_POSITIVE_HPP
#define FIRST_MISSING_POSITIVE_HPP

#include <vector>

/**
 * Given an unsorted integer array, find the smallest missing positive integer
 */
namespace first_missing_positive {

    using namespace std;

    int solution(vector<int> &nums) {
        int max_integer = nums.size();
        vector<int> record(max_integer + 1, 0);
        // 遍历数组并记录值在[1, max_integer]之间的访问情况
        for(vector<int>::const_iterator iter = nums.cbegin();
                iter != nums.cend(); iter++) {
            int num = *iter;
            if(num > 0 && num <= max_integer) {
                record[num] = 1;
            }
        }
        // 遍历记录情况，出现第一个0直接返回；如果都是1，则返回最大整数+1
        for(int i = 1; i <= max_integer; ++i) {
            if(!record[i])
                return i;
        }
        return max_integer + 1;
    }

    int solution_1(vector<int> &nums) {
        int len = nums.size();

        for(int i = 0; i < len; ++i) {
            int num = nums[i];
            while(num > 0 && num <= len && nums[num - 1] != num) {
                nums[i] = nums[num - 1];
                nums[num - 1] = num;
                num = nums[i];      // swap后的当前位置值仍需进行判断
            }
        }

        for(int i = 0; i< len; ++i) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return len + 1;
    }
}

#endif