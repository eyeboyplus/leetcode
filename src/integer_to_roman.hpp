//
// Created by eyeboy on 2018/6/26.
//

#ifndef LEETCODE_INTEGER_TO_ROMAN_HPP
#define LEETCODE_INTEGER_TO_ROMAN_HPP

#include <string>

using namespace std;

/**
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
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
    Because the one is before the five we subtract it making four.
    The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
        I can be placed before V (5) and X (10) to make 4 and 9.
        X can be placed before L (50) and C (100) to make 40 and 90.
        C can be placed before D (500) and M (1000) to make 400 and 900.
    Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 */

string solution_1(int num) {
    int digit = 1;
    int n = 0;
    string result;
    while(num != 0) {
        n = num % 10;

        string symbol;
        string roman_num_1, roman_num_5, roman_num_10;
        switch(digit) {
            case 1: {
                roman_num_1 = "I";
                roman_num_5 = "V";
                roman_num_10 = "X";
                break;
            }
            case 10: {
                roman_num_1 = "X";
                roman_num_5 = "L";
                roman_num_10 = "C";
                break;
            }
            case 100: {
                roman_num_1 = "C";
                roman_num_5 = "D";
                roman_num_10 = "M";
                break;
            }
            case 1000: {
                roman_num_1 = "M";
                roman_num_5 = ".";
                roman_num_10 = ".";
                break;
            }
        }

        if(n >=1 && n<=3) {
            for(int i=0; i<n; ++i)
                symbol += roman_num_1;
        } else if(n == 4) {
            symbol = roman_num_1 + roman_num_5;
        } else if(n == 5) {
            symbol = roman_num_5;
        } else if(n > 5 && n <= 8) {
            symbol = roman_num_5;
            for(int i=0; i<n - 5; ++i)
                symbol += roman_num_1;
        } else if(n == 9) {
            symbol = roman_num_1 + roman_num_10;
        } else {    // n == 0

        }

        result.insert(0, symbol, 0, symbol.size());

        num = num / 10;
        digit *= 10;
    }
    return result;
}

#endif //LEETCODE_INTEGER_TO_ROMAN_HPP
