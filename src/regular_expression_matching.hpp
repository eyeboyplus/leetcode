//
// Created by eyeboy on 2018/6/24.
//

#ifndef LEETCODE_REGULAR_EXPRESSION_MATCHING_HPP
#define LEETCODE_REGULAR_EXPRESSION_MATCHING_HPP

/**
 *  Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *  '.' Matches any single character.
 *  '*' Matches zero or more of the preceding element.
 *  The matching should cover the entire input string (not partial).
 *  Note:
 *  s could be empty and contains only lowercase letters a-z.
 *  p could be empty and contains only lowercase letters a-z, and characters like . or *.
 */

#include <string>
#include <iostream>

using namespace std;

namespace regular_expression_matching {
    // brute force
    bool solution_1(string s, string p) {
        if(p.empty()) return s.empty();

        if(p.length() == 1) {
            if(s.empty())
                return false;

            if(s.length() == 1)
                return p[0] == s[0] || p[0] == '.';
        }

        if(p[1] != '*') {      // the second character of pattern string is not *
            if(s.empty())
                return false;

            return (p[0] == s[0] || p[0] == '.') && solution_1(s.substr(1), p.substr(1));
        } else {              // the second character of pattern string is *
            // can not determine the number of duplicate charaters, we have to try all possibilities
            while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
                if(solution_1(s, p.substr(2))) return true;
                s = s.substr(1);
            }
            return solution_1(s, p.substr(2));
        }
    }

    // dynamic programming
    // (1) https://leetcode.com/problems/regular-expression-matching/discuss/5684/9-lines-16ms-c-dp-solutions-with-explanations
    // (2) https://blog.csdn.net/linhuanmars/article/details/21145563
    bool solution_2(string s, string p) {
    }
}

#endif //LEETCODE_REGULAR_EXPRESSION_MATCHING_HPP
