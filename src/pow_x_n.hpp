//
// Created by eyeboy on 2018/8/9.
//

#ifndef LEETCODE_POW_X_N_HPP
#define LEETCODE_POW_X_N_HPP

/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
    Example 1:
    Input: 2.00000, 10
    Output: 1024.00000
    Example 2:
    Input: 2.10000, 3
    Output: 9.26100
    Example 3:
    Input: 2.00000, -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
    Note:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */
namespace pow_x_n {
    double recursive(double x, int positive_n) {
        if(positive_n == 1)
            return x;

        double r1, r2, ret;
        if(positive_n % 2 == 0) {
            r1 = recursive(x, positive_n / 2);
            r2 = r1;
        } else {
            r1 = recursive(x, positive_n / 2);
            r2 = r1 * x;
        }
        ret = r1 * r2;

        return ret;
    }

    double solution_1(double x, int n) {
        if(n == 0)
            return 1.0;

        if(x == 1)
            return 1.0;

        if(x == -1)
            return (n % 2 == 0) ?  1.0 : -1.0;

        if(n < 0) {
            return (1 / recursive(x, -n));
        } else {
            return recursive(x, n);
        }
    }

    double solution_2(double x, int n) {
        if(n == 0)
            return 1.0;

        if(x == 1)
            return 1.0;

        if(x == -1)
            return (n % 2 == 0) ?  1.0 : -1.0;

        int pn = n;
        if(n < 0)
            pn = -n;

        int cnt = 1, base_cnt = 1;
        double base = x;
        double ret = base;
        while(cnt + base_cnt <= pn) {
            ret *= base;
            cnt += base_cnt;

            base *= base;
            base_cnt *= 2;
        }

        for(int i = 0; i < pn - cnt; ++i) {
            ret *= x;
        }

        if(n < 0)
            return 1 / ret;
        return ret;
    }

    double solution(double x, int n) {
        if(n < 0)
            return (1/x) * solution(1/x, -(n + 1));
        if(n == 0)
            return 1.0;
        if(n == 2)
            return x * x;
        if(n % 2 == 0)
            return solution(solution(x, n / 2), 2);
        else
            return x * solution(solution(x, n / 2), 2);
    }
}

#endif //LEETCODE_POW_X_N_HPP
