//
// Created by eyeboy on 2018/8/14.
//

#ifndef LEETCODE_N_QUEENS_II_HPP
#define LEETCODE_N_QUEENS_II_HPP

#include <string>
#include <vector>

/**
 *
 */
namespace n_queens_ii {
    using namespace std;
    void recursive(int n, int level, vector<string> board, int &ret) {
        if(level == n) {
            ret ++;
            return;
        }

        for(int i = 0; i < n; ++i) {
            string level_str(n, '.');
            level_str[i] = 'Q';

            bool isValid = true;
            int left = i, right = i;
            for(int j = level - 1; j >= 0; --j) {
                string s = board[j];
                if(s[i] == 'Q') {
                    isValid = false;
                    break;
                }
                if(left - 1 >= 0 && s[--left] == 'Q') {
                    isValid = false;
                    break;
                }
                if(right + 1 <= n - 1 && s[++right] == 'Q') {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                board.push_back(level_str);
                recursive(n, level + 1, board, ret);
                board.pop_back();
            }
        }
    }

    int solution(int n) {
        vector<string> board;
        int ret = 0;
        recursive(n, 0, board, ret);
        return ret;
    }
}

#endif //LEETCODE_N_QUEENS_II_HPP
