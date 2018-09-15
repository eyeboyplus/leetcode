//
// Created by eyeboy on 2018/9/15.
//

#ifndef LEETCODE_SQRT_X_HPP
#define LEETCODE_SQRT_X_HPP

#include <climits>
#include <cmath>

/**
 * Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
Example 1:
    Input: 4
    Output: 2
Example 2:
    Input: 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since
                 the decimal part is truncated, 2 is returned.
 */
namespace sqrt_x {
    using namespace std;

    int solution(int x) {
        if(x == 0)
            return 0;

        if(x == 1)
            return 1;

        int ret = 0;
        for(int i = 1; i <= x / 2; ++i) {
            int dist = i * i - x;
            if(dist > 0) {
                return ret;
            }
            else {
                ret = i;
            }
        }

        return ret;
    }
}


#endif //LEETCODE_SQRT_X_HPP
