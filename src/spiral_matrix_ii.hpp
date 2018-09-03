//
// Created by eyeboy on 2018/9/3.
//

#ifndef LEETCODE_SPIRAL_MATRIX_II_HPP
#define LEETCODE_SPIRAL_MATRIX_II_HPP

#include <vector>

/**
 * Given a positive integer n,
 * generate a square matrix filled with elements from 1 to n2 in spiral order.
Example:
    Input: 3
    Output:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
    ]
 */
namespace spiral_matrix_ii {
    using namespace std;

    vector<vector<int>> solution(int n) {
        vector<vector<int>> ret(n, vector<int>(n));

        int xStart = 0, yStart = 0, value = 0;
        int xEnd = n - 1, yEnd = n - 1;
        while(xStart < xEnd && yStart < yEnd) {
            // top
            for(int j = yStart; j <= yEnd; ++j)
                ret[xStart][j] = (++value);

            // right
            for(int i = xStart + 1; i <= xEnd - 1; ++i)
                ret[i][yEnd] = (++value);

            // bottom
            for(int j = yEnd; j >= yStart; --j)
                ret[xEnd][j] = (++value);

            // left
            for(int i = xEnd - 1; i >= xStart + 1; --i)
                ret[i][yStart] = (++value);

            xStart ++; xEnd --;
            yStart ++; yEnd --;
        }

        if(xStart == xEnd && yStart == yEnd)
            ret[xStart][yStart] = (++value);

        return ret;
    }
}

#endif //LEETCODE_SPIRAL_MATRIX_II_HPP
