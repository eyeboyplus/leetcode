//
// Created by eyeboy on 2018/9/11.
//

#ifndef LEETCODE_PLUS_ONE_HPP
#define LEETCODE_PLUS_ONE_HPP

#include <vector>

/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list,
 and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.
Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
 */
namespace plus_one {

    using namespace std;

    vector<int> solution(vector<int> &digits) {
        int carry = 0;
        vector<int>::reverse_iterator iter = digits.rbegin();
        int d = *iter + 1 + carry;
        *iter = d % 10;
        carry = d / 10;
        while((++iter) != digits.rend() && carry != 0) {
            d = *iter + carry;
            *iter = d % 10;
            carry = d / 10;
        }

        if(carry != 0)
            digits.insert(digits.begin(), carry);

        return digits;
    }
}

#endif //LEETCODE_PLUS_ONE_HPP
