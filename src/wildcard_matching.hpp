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
        if(p.empty()) return s.empty();

        if(p.length() == 1) {
            if(p[0] == '*')
                return true;

            if(s.empty())
                return false;

            if(s.length() == 1)
                return p[0] == s[0] || p[0] == '?';
        }

        if(p[0] != '*') {
            if(s.empty())
                return false;

            return (p[0] == s[0] || p[0] == '?') && solution_1(s.substr(1), p.substr(1));
        } else {
            while(!s.empty()) {
                if(solution_1(s, p.substr(1))) return true;
                s = s.substr(1);
            }

            for(string::const_iterator iterator = p.cbegin(); iterator != p.cend(); ++iterator) {
                if(*iterator != '*')
                    return false;
            }
            return true;
        }
    }
}
#endif
