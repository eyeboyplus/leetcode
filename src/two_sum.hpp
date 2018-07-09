//
// Created by eyeboy on 2018/7/7.
//

#ifndef LEETCODE_TWO_SUM_HPP
#define LEETCODE_TWO_SUM_HPP

#include <vector>
#include <algorithm>

namespace two_sum {
    using namespace std;

    vector<int> solution_2(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        vector<int> result;
        if(len < 2)
            return result;

        int left = 0, right = len - 1;
        while(left < right) {
            int value = nums[left] + nums[right];
            if(value == target){            // 最终结果
                result.push_back(left);
                result.push_back(right);
                return result;
            } else if(value < target) {     // 向右逼近
                left ++;
            } else {                        // 向左逼近
                right --;
            }
        }
        return result;
    }
}

#endif //LEETCODE_TWO_SUM_HPP
