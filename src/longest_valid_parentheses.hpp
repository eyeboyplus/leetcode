//
// Created by eyeboy on 2018/7/13.
//

#ifndef LEETCODE_LONGEST_VALID_PARENTHESES_HPP
#define LEETCODE_LONGEST_VALID_PARENTHESES_HPP

#include <string>
#include <stack>

/**
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
    Example 1:
    Input: "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()"

     Example 2:
    Input: ")()())"
    Output: 4
    Explanation: The longest valid parentheses substring is "()()"
 */
namespace longest_valid_parentheses {
    using namespace std;

    bool is_valid_parentheses(string s, int index, int len) {
        stack<char> open_stack;

        int size = s.size();
        if(index + len > size)
            return false;

        for(int i = index; i < index + len; ++i) {
            char c = s[i];

            if(c == '(')
                open_stack.push(c);
            else if(c == ')') {
                if(open_stack.empty()) {
                    return false;
                } else {
                    open_stack.pop();
                }
            }
        }

        if(open_stack.empty())
            return true;

        return false;
    }

    // Time limit exceeded
    int solution_1(string s) {
        int len = s.size();

        int result = 0;
        for(int i = 2; i <= len; i += 2) {
            for(int j = 0; j + i - 1 < len; ++j) {
                if(is_valid_parentheses(s, j, i) && result < i) {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }

    int solution_2(string s) {
        int len = s.size();

        stack<int> open_idx_stack;
        int start = 0, ret = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') {
                open_idx_stack.push(i);
            } else {
                if(open_idx_stack.empty()) {
                    start = i + 1;
                } else {
                    open_idx_stack.pop();

                    if(open_idx_stack.empty() && ret < i - start + 1) {
                        ret = i - start + 1;
                    }

                    if(!open_idx_stack.empty() && ret < i - open_idx_stack.top())
                        ret = i - open_idx_stack.top();
                }
            }
        }

        return ret;
    }
}

#endif //LEETCODE_LONGEST_VALID_PARENTHESES_HPP
