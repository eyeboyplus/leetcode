//
// Created by eyeboy on 2018/9/7.
//

#ifndef LEETCODE_UNIQUE_PATHS_II_HPP
#define LEETCODE_UNIQUE_PATHS_II_HPP

#include <vector>

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the
 bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
 Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 */
namespace unique_paths_ii {
    using namespace std;

    int solution(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;

        int n = obstacleGrid[0].size();

        vector<vector<int>> paths (m, vector<int>(n, 1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                    continue;
                }
                if(i - 1 < 0 && j - 1 >= 0)
                    paths[i][j] = paths[i][j - 1];

                if(j - 1 < 0 && i - 1 >= 0)
                    paths[i][j] = paths[i - 1][j];

                if(j - 1 >= 0 && i - 1 >= 0)
                    paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }

        return paths[m - 1][n - 1];
    }
}

#endif //LEETCODE_UNIQUE_PATHS_II_HPP
