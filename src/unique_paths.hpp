//
// Created by eyeboy on 2018/9/6.
//

#ifndef LEETCODE_UNIQUE_PATHS_HPP
#define LEETCODE_UNIQUE_PATHS_HPP

#include <vector>

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time.
 The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Example 1:
    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right
Example 2:
    Input: m = 7, n = 3
    Output: 28
 */
namespace unique_paths {

    using namespace std;

    void recursive(int l1, int l2, int &count) {
        if(l1 == 0 || l2 == 0) {
            count ++;
            return;
        }

        recursive(l1 - 1, l2, count);
        recursive(l1, l2 - 1, count);
    }

    // Time Limit Exceeded
    int solution_1(int m, int n) {
        int ret = 0;
        recursive(m - 1, n - 1, ret);
        return ret;
    }

    int solution_2(int m, int n) {
        vector<vector<int>> path(m, vector<int> (n, 1));

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                path[i][j] = path[i - 1][j] + path[i][j - 1];

        return path[m - 1][n - 1];
    }
}

#endif //LEETCODE_UNIQUE_PATHS_HPP
