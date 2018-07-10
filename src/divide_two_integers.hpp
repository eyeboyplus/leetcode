//
// Created by eyeboy on 2018/7/7.
//
#ifndef LEETCODE_DIVIDE_TWO_INTEGERS_HPP
#define LEETCODE_DIVIDE_TWO_INTEGERS_HPP

#include <climits>

/**
 * Given two integers dividend and divisor,
 * divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 */
namespace divide_two_integers {
    // 被除数减去除数, 优化
    int solution_1(int dividend, int divisor) {
        if(dividend == 0) return 0;

        if(dividend == INT_MIN) {
            if(divisor == -1)       // 溢出
                return INT_MAX;
            else if (divisor < 0)       // 确保被除数和除数取绝对值不会发生溢出, 提前减去一个除数，是被除数小于INT_MAX
                return 1 + solution_1(dividend - divisor, divisor);
            else                        // 确保被除数和除数取绝对值不会发生溢出, 提前加上一个除数，是被除数小于INT_MAX
                return -1 + solution_1(dividend + divisor, divisor);
        }

        if(divisor == INT_MIN) {
            return dividend == INT_MIN ? 1:0;
        }

        int positive_dividend = dividend < 0 ? -dividend : dividend;
        int positive_divisor = divisor < 0 ? -divisor : divisor;

        int result = 0;
        while(positive_dividend >= positive_divisor) {
            int d = positive_divisor;
            for(int i = 0; positive_dividend >= d;) {
                positive_dividend -= d;
                result += 1 << i;
                if(d < INT_MAX / 2) {
                    i++;
                    d <<= 1;
                }
            }

        }
        return ((dividend ^ divisor) >> 31) ? (-result) : result;
    }
}

#endif //LEETCODE_DIVIDE_TWO_INTEGERS_HPP
