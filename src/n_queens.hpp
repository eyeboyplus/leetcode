//
// Created by eyeboy on 2018/8/13.
//

#ifndef LEETCODE_N_QUEENS_HPP
#define LEETCODE_N_QUEENS_HPP

#include <vector>
#include <string>

/**
 * The n-queens puzzle is the problem of placing n queens on an n*n chessboard
 * such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queen's placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectly
 * Example:
 *  Input: 4
 *  Output: [
 *      [".Q.."],
 *      ["...Q"],
 *      ["Q..."],
 *      ["..Q."]
 *
 *      ["..Q."],
 *      ["Q..."],
 *      ["...Q"],
 *      [".Q.."]
 *
 *  ]
 */
namespace n_queens {
    using namespace std;
    void recursive(int level, int n, vector<string> board, vector<vector<string>> &ret) {
        if(level == n) {
            ret.push_back(board);
            return;
        }

        for(int i = 0; i < n; ++i) {
            string level_str(n, '.');
            level_str[i] = 'Q';

            bool isValid = true;
            int left = i, right = i;
            for(int j = level - 1; j >= 0; --j) {
                string s = board[j];
                // check column
                if(s[i] == 'Q') {
                    isValid = false;
                    break;
                }
                if(left - 1 >= 0) {
                    if(s[--left] == 'Q') {
                        isValid = false;
                        break;
                    }
                }

                if(right + 1 < n) {
                    if(s[++right] == 'Q') {
                        isValid = false;
                        break;
                    }
                }
            }

            if(!isValid)
                continue;

            board.push_back(level_str);
            recursive(level + 1, n, board, ret);
            board.pop_back();
        }
    }

    vector<vector<string>> solution(int n) {
        vector<vector<string>> ret;
        vector<string> board;
        recursive(0, n, board, ret);
        return ret;
    }
}

#endif //LEETCODE_N_QUEENS_HPP
