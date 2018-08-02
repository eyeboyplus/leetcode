//
// Created by eyeboy on 2018/8/1.
//

#ifndef LEETCODE_JUMP_GAME_II_HPP
#define LEETCODE_JUMP_GAME_II_HPP

#include <vector>

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.
    Example:
        Input: [2,3,1,1,4]
        Output: 2
        Explanation: The minimum number of jumps to reach the last index is 2.
            Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Note: You can assume that you can always reach the last index.
 */
namespace jump_game_ii {

    using namespace std;

    void dfs(vector<int> &nums, int pos, int jump, int &ret) {
        int len = nums.size();
        if(pos >= len - 1) {
            if(jump < ret)
                ret = jump;
            return;
        }

        int cnt = nums[pos];
        int index = pos, target = pos;
        if(cnt + pos < len - 1) {
            for(int i = 1; i <= cnt; i++) {
                if(pos + i < len - 1) {
                    if(pos + i + nums[pos + i] > target) {
                        index = pos + i;
                        target = pos + i + nums[pos + i];
                    }
                } else {
                    index = len - 1;
                    break;
                }
            }
        } else {
            index = len - 1;
        }

        dfs(nums, index, jump + 1, ret);
    }

    int solution_1(vector<int> &nums) {
        int ret = nums.size();
        dfs(nums, 0, 0, ret);
        return ret;
    }

    int solution_2(vector<int> nums) {
        int len = nums.size();
        if(len < 2)
            return 0;
        // i 每层的起始位置,currentMax 每层的结束位置,
        // level 层数, nextMax 下一层所有能到达的最大位置
        int i = 0, currentMax = 0, level = 0, nextMax = 0;
        while(currentMax - i + 1 > 0) {
            level ++;
            for(; i <= currentMax; ++i) {
                if(nums[i] + i > nextMax)
                    nextMax = nums[i] + i;
                if(nextMax >= len - 1) return level;
            }
            currentMax = nextMax;
        }
        return 0;
    }
}

#endif //LEETCODE_JUMP_GAME_II_HPP
