#ifndef LEETCODE_WILDCARD_MATCHING_HPP
#define LEETCODE_WILDCARD_MATCHING_HPP

#include <string>
#include <iostream>

using namespace std;
/**
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 *   '?' Matches any single character.
 *   '*' Matches any sequence of characters (including the empty sequence).
 *   The matching should cover the entire input string (not partial).
 *   Note:
 *   s could be empty and contains only lowercase letters a-z.
 *   p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 * */

namespace wildcard_matching {
    // brute force, Time Limit Exceeded
    // O(n!*m!),O(n)
    bool solution_1(string s, string p) {
        if(p.empty()) return s.empty();         // 模式串为空，主串为空匹配成功，否则失败

        if(p.length() == 1) {
            if(p[0] == '*') {   // 模式串为“*”，匹配任意
                return true;
            } else {            // 模式串不为“*”
                if(s.empty()) { // 主串为空
                    return false;
                } else if(s.length() == 1) {    // 主串长度为1的情形
                    return p[0] == s[0] || p[0] == '?';
                } else {        // 主串长度大于1的情形
                    return false;
                }
            }
        }

        // 以下为模式串长度大于1的情形
        if(p[0] != '*') {
            if(s.empty())       // 主串为空，不能匹配
                return false;

            // 主串非空，匹配第一位，并递归匹配剩余部分
            return (p[0] == s[0] || p[0] == '?') && solution_1(s.substr(1), p.substr(1));
        } else {
            // 模式串第一个是"*",则尝试"*"替代主串中0、1、2、...个字符
            while(!s.empty()) {
                if(solution_1(s, p.substr(1))) return true;
                s = s.substr(1);
            }
            // 剩余模式串的长度大于1，并且剩余主串为空；当前仅当剩余模式串全为"*"时，匹配成功
            for(string::const_iterator iterator = p.cbegin(); iterator != p.cend(); ++iterator) {
                if(*iterator != '*')
                    return false;
            }
            return true;
        }
    }
}
#endif
