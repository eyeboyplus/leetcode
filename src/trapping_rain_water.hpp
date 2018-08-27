//
// Created by eyeboy on 2018/7/26.
//

#ifndef LEETCODE_TRAPPING_RAIN_WATER_HPP
#define LEETCODE_TRAPPING_RAIN_WATER_HPP

#include <vector>

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 */
namespace trapping_rain_water {
    using namespace std;

    int solution(vector<int> &height) {
        int length = height.size();

        if(length < 3)
            return 0;

        vector<int> leftMaxHeight(length, 0);
        vector<int> rightMaxHeight(length, 0);
        leftMaxHeight[0] = height[0];
        rightMaxHeight[length - 1] = height[length - 1];
        for(int i = 1; i < length - 1; ++i) {
            if(height[i - 1] > leftMaxHeight[i - 1])
                leftMaxHeight[i] = height[i - 1];
            else
                leftMaxHeight[i] = leftMaxHeight[i - 1];

            if(height[length - i] > rightMaxHeight[length - i])
                rightMaxHeight[length - i - 1] = height[length - i];
            else
                rightMaxHeight[length - i - 1] = rightMaxHeight[length - i];
        }

        int ret = 0;

        for(int i = 1; i < length - 1; ++i) {
            int h = leftMaxHeight[i] < rightMaxHeight[i] ? leftMaxHeight[i] : rightMaxHeight[i];
            if(h > height[i])
                ret += (h - height[i]);
        }

        return ret;
    }
}

#endif //LEETCODE_TRAPPING_RAIN_WATER_HPP
