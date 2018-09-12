//
// Created by eyeboy on 2018/9/12.
//

#ifndef LEETCODE_ADD_BINARY_HPP
#define LEETCODE_ADD_BINARY_HPP

#include <string>

/**
 * Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 */
namespace add_binary {
    using namespace std;

    string solution(string a, string b) {
        string::reverse_iterator iter_a = a.rbegin();
        string::reverse_iterator iter_b = b.rbegin();

        string ret;

        int carray = 0;
        while(iter_a != a.rend() && iter_b != b.rend()) {
            int d = ((*iter_a) - '0') + ((*iter_b) - '0') + carray;
            carray = d / 2;
            ret.insert(ret.begin(), (d % 2) + '0');

            iter_a ++; iter_b ++;
        }

        while(iter_a != a.rend()) {
            int d = ((*iter_a) - '0') + carray;
            carray = d / 2;
            ret.insert(ret.begin(), (d % 2) + '0');
            iter_a ++;
        }

        while(iter_b != b.rend()) {
            int d = ((*iter_b) - '0') + carray;
            carray = d / 2;
            ret.insert(ret.begin(), (d % 2) + '0');
            iter_b ++;
        }

        if(carray != 0)
            ret.insert(ret.begin(), carray + '0');

        return ret;
    }
}

#endif //LEETCODE_ADD_BINARY_HPP
