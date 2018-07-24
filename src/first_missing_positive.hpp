//
// Created by eyeboy on 2018/7/24.
//
#ifndef FIRST_MISSING_POSITIVE_HPP
#define FIRST_MISSING_POSITIVE_HPP

#include <vector>

/**
 * Given an unsorted integer array, find the smallest missing positive integer
 */
namespace first_missing_positive {

    using namespace std;

    int solution(vector<int> &nums) {

        int max_integer = nums.size();
        vector<int> record(max_integer + 1, 0);
        int ret = 1;
        for(vector<int>::const_iterator iter = nums.cbegin(); iter != nums.cend(); iter++) {
            int num = *iter;

            if(num > 0 && num <= max_integer) {
                record[num] = 1;
            }
        }

        for(int i = 1; i <= max_integer; ++i) {
            if(!record[i])
                return i;
        }

        return max_integer + 1;
    }
}

#endif