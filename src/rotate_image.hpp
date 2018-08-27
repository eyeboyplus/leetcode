//
// Created by eyeboy on 2018/8/7.
//

#ifndef LEETCODE_ROTATE_IMAGE_HPP
#define LEETCODE_ROTATE_IMAGE_HPP

#include <vector>

/**
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
    Note:
    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 */
namespace rotate_image {
    using namespace std;

    void solution(vector<vector<int>> &matrix) {

        int n = matrix.size();
        if(n <= 1)
            return;

        vector<vector<int>> duplicate = matrix;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                matrix[j][n - 1 - i] = duplicate[i][j];
            }
        }
    }
}

#endif //LEETCODE_ROTATE_IMAGE_HPP
