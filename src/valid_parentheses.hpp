//
// Created by eyeboy on 2018/7/1.
//

#ifndef LEETCODE_VALID_PARENTHESES_HPP
#define LEETCODE_VALID_PARENTHESES_HPP

#include <string>
#include <stack>

using namespace std;

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Note that an empty string is also considered valid.
 */
namespace valid_parentheses {

    /**
     * stack
     */
    bool solution(string s) {
        if(s.empty())
            return true;

        stack<char> stack;
        for(string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter) {
            switch(*iter) {
                case '(':
                case '{':
                case '[': {
                    stack.push(*iter);
                    break;
                }
                case ')': {
                    if(!stack.empty() && stack.top() == '(') {
                        stack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
                case '}': {
                    if(!stack.empty() && stack.top() == '{') {
                        stack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
                case ']': {
                    if(!stack.empty() && stack.top() == '[') {
                        stack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
            }
        }

        if(!stack.empty())
            return false;

        return true;
    }
}

#endif //LEETCODE_VALID_PARENTHESES_HPP
