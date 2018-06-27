//
// Created by eyeboy on 2018/6/27.
//

#ifndef LEETCODE_ROMAN_TO_INTEGER_HPP
#define LEETCODE_ROMAN_TO_INTEGER_HPP

#include <string>

using namespace std;

/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together.
    Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right.
    However, the numeral for four is not IIII. Instead, the number four is written as IV.
    Because the one is before the five we subtract it making four. The same principle applies to the number nine,
    which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 */

namespace roman_to_integer {
    int romanToInt(string s) {
        int len = s.size();

        int result = 0;
        for(int i=0; i<len; ++i) {
            switch(s[i]) {
                case 'I': {
                    int val = 0;
                    if((i+1) < len && s[i+1] == 'V') {
                        val = 4;
                        i = i + 1;
                    } else if((i+1) < len && s[i+1] == 'X') {
                        val = 9;
                        i = i + 1;
                    } else {
                        val = 1;
                    }
                    result += val;
                    break;
                }
                case 'V': {
                    result += 5;
                    break;
                }
                case 'X': {
                    int val = 0;
                    if((i+1) < len && s[i+1] == 'L') {
                        val = 40;
                        i = i + 1;
                    } else if((i+1) < len && s[i+1] == 'C') {
                        val = 90;
                        i = i + 1;
                    } else {
                        val = 10;
                    }
                    result += val;
                    break;
                }
                case 'L': {
                    result += 50;
                    break;
                }
                case 'C': {
                    int val = 0;
                    if((i+1) < len && s[i+1] == 'D') {
                        val = 400;
                        i = i + 1;
                    } else if((i+1) < len && s[i+1] == 'M') {
                        val = 900;
                        i = i + 1;
                    } else {
                        val = 100;
                    }
                    result += val;
                    break;
                }
                case 'D': {
                    result += 500;
                    break;
                }
                case 'M': {
                    result += 1000;
                    break;
                }
            }
        }
        return result;
    }
}

#endif //LEETCODE_ROMAN_TO_INTEGER_HPP
