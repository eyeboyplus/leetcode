//
// Created by eyeboy on 2018/9/17.
//

#ifndef LEETCODE_CLIMBING_STAIRS_HPP
#define LEETCODE_CLIMBING_STAIRS_HPP

#include <vector>

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
Example 2:
    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
 */
namespace climbing_stairs {
    using namespace std;

    void recursive(int n, int cnt, int &ret) {
        if(cnt == n) {
            ret ++;
            return;
        } else if(cnt > n) {
            return;
        }

        recursive(n, cnt + 1, ret);
        recursive(n, cnt + 2, ret);
    }

    int solution_1(int n) {
        int cnt = 0, ret = 0;
        recursive(n, cnt, ret);
        return ret;
    }

    int solution_2(int n) {
        vector<int> counts = vector<int>(n + 1, 0);
        counts[0] = 0;
        for(int i = 1; i <= n; ++i) {
            if(i == 1)
                counts[i] = 1;
            else if(i == 2)
                counts[i] = 2;
            else
                counts[i] = counts[i - 1] + counts[i - 2];
        }
        return counts[n];
    }
}

#endif //LEETCODE_CLIMBING_STAIRS_HPP
