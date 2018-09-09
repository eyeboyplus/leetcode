//
// Created by eyeboy on 2018/9/9.
//

#ifndef LEETCODE_MINIMUM_PATH_SUM_HPP
#define LEETCODE_MINIMUM_PATH_SUM_HPP

#include <vector>
#include <cmath>

/**
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes
 * the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
    Input:
    [
      [1,3,1],
      [1,5,1],
      [4,2,1]
    ]
    Output: 7
    Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
namespace minimum_path_sum {
    using namespace std;

    int solution(vector<vector<int>> &grid) {
        int m = grid.size();

        if(m == 0)
            return 0;

        int n = grid[0].size();
        vector<vector<int>> paths = grid;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j - 1 < 0 && i - 1 >= 0)
                    paths[i][j] += paths[i - 1][j];

                if(j - 1 >= 0 && i - 1 < 0)
                    paths[i][j] += paths[i][j - 1];

                if(j - 1 >=0 && i - 1 >= 0)
                    paths[i][j] += min(paths[i][j - 1], paths[i - 1][j]);
            }
        }
        return paths[m - 1][n - 1];
    }
}

#endif //LEETCODE_MINIMUM_PATH_SUM_HPP
