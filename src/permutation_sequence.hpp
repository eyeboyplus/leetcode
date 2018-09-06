//
// Created by eyeboy on 2018/9/4.
//

#ifndef LEETCODE_PERMUTATION_SEQUENCE_HPP
#define LEETCODE_PERMUTATION_SEQUENCE_HPP

#include <string>
#include <vector>

/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
    By listing and labeling all of the permutations in order,
    we get the following sequence for n = 3:
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    Given n and k, return the kth permutation sequence.
    Note:
    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.
    Example 1:
    Input: n = 3, k = 3
    Output: "213"
    Example 2:
    Input: n = 4, k = 9
    Output: "2314"
 */
namespace permutation_sequence {
    using namespace std;

    void recursive(vector<int> nums, string path, int &count, int k, string &ret) {

        if(nums.empty()) {
            if((++count) == k)
                ret = path;
            return;
        }

        for(vector<int>::iterator iter = nums.begin();
                iter != nums.end(); iter++) {
            path.push_back('0' + (*iter));
            vector<int> newVec;
            newVec.insert(newVec.end(), nums.begin(), iter);
            newVec.insert(newVec.end(), iter + 1, nums.end());
            recursive(newVec, path, count, k, ret);
            path.pop_back();
        }
    }
    // time limit exceeded
    string solution(int n, int k) {
        vector<int> vec;
        for(int i = 1; i <= n; ++i)
            vec.push_back(i);

        string ret, path;
        int count = 0;
        recursive(vec, path, count, k, ret);

        return ret;
    }
}

#endif //LEETCODE_PERMUTATION_SEQUENCE_HPP
