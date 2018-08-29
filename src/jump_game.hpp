//
// Created by eyeboy on 2018/8/29.
//

#ifndef LEETCODE_JUMP_GAME_HPP
#define LEETCODE_JUMP_GAME_HPP

#include <vector>

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Determine if you are able to reach the last index.
    Example 1:
    Input: [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:
    Input: [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum
                 jump length is 0, which makes it impossible to reach the last index.
 */
namespace jump_game {
    using namespace std;

    void recursive(vector<int> &nums, int index, bool &ret) {
        if(index >= nums.size() - 1) {
            ret = true;
            return;
        }

        int jump = nums[index];
        for(int i = 1; i <= jump; ++i) {
            recursive(nums, index + i, ret);
        }
    }

    // Time Limit Exceeded
    bool solution_1(vector<int> &nums) {
        if(nums.size() == 1)
            return true;

        bool ret = false;
        recursive(nums, 0, ret);
        return ret;
    }

    bool solution_2(vector<int> &nums) {
        int size = nums.size();

        int i = 0, curMaxPos = 0, nextMaxPos = 0;
        while(curMaxPos - i + 1 > 0) {
            for(; i <= curMaxPos; ++i) {
                if(nums[i] + i > nextMaxPos)
                    nextMaxPos = nums[i] + i;
                if(nextMaxPos >= size - 1)
                    return true;
            }
            curMaxPos = nextMaxPos;
        }
        return false;
    }
}

#endif //LEETCODE_JUMP_GAME_HPP
