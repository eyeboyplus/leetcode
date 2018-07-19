//
// Created by eyeboy on 2018/7/19.
//

#ifndef LEETCODE_COUNT_AND_SAY_HPP
#define LEETCODE_COUNT_AND_SAY_HPP

#include <string>

/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221
    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth term of the count-and-say sequence.
    Note: Each term of the sequence of integers will be represented as a string.
 */
namespace count_and_say {
    using namespace std;

    string solution(int n) {
        if(n == 1)
            return "1";

        string s = solution(n - 1);

        string ret;
        int cnt = 1;
        char prev = s[0];
        int len = s.size();
        for(int i = 1; i < len; ++i) {
            char c = s[i];
            if(c == prev) {
                cnt ++;
            } else {
                ret.push_back(cnt + '0');
                ret.push_back(prev);

                cnt = 1;
                prev = c;
            }
        }

        ret.push_back(cnt + '0');
        ret.push_back(prev);

        return ret;
    }
}

#endif //LEETCODE_COUNT_AND_SAY_HPP
