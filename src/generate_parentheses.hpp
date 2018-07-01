//
// Created by eyeboy on 2018/7/1.
//

#ifndef LEETCODE_GENERATE_PARENTHESES_HPP
#define LEETCODE_GENERATE_PARENTHESES_HPP

#include <string>
#include <vector>

using namespace std;

/**
 * Given n pairs of parentheses,
 * write a function to generate all combinations of well-formed parentheses.
    For example, given n = 3, a solution set is:
    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
 */
namespace generate_parentheses {

    void dfs(int open_remainder, int close_remainder, string path, vector<string> &result) {
        if(close_remainder < open_remainder)
            return;

        if(open_remainder == 0 && close_remainder == 0) {
            result.push_back(path);
        } else {
            if(open_remainder > 0) dfs(open_remainder - 1, close_remainder, path + "(", result);
            if(close_remainder > 0) dfs(open_remainder, close_remainder - 1, path + ")", result);
        }
    }
    /**
     * 深度优先思想
     * 1. open_remainder，close_remainder分别表示左右括号剩余数量
     * 2. 只有左括号先添加的情况下，组成的字符串才是合法
     */
    vector<string> solution_1(int n) {
        vector<string> result;
        string path;
        dfs(n, n, path, result);
        return result;
    }
}

#endif //LEETCODE_GENERATE_PARENTHESES_HPP
