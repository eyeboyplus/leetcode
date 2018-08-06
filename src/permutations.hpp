//
// Created by eyeboy on 2018/8/2.
//

#ifndef LEETCODE_PERMUTATIONS_HPP
#define LEETCODE_PERMUTATIONS_HPP

#include <vector>

/**
 *Given a collection of distinct integers, return all possible permutations.
Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
namespace permutations {

    using namespace std;

    void recursive(vector<int> nums, vector<int> path, vector<vector<int>> &result) {
        if(nums.empty()) {
            result.push_back(path);
            return;
        }
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            int num = *iter;
            path.push_back(num);
            // 剔除当前数，其他数当做下一层数据
            vector<int> temp;
            if(iter - 1 >= nums.begin())
                temp.insert(temp.end(), nums.begin(), iter);
            if(iter + 1 <= nums.end())
                temp.insert(temp.end(), iter + 1, nums.end());
            // 递归
            recursive(temp, path, result);

            path.pop_back();
        }
    }
    vector<vector<int>> solution(vector<int> &nums) {
        vector<int> path;
        vector<vector<int>> ret;
        recursive(nums, path, ret);
        return ret;
    }
}

#endif //LEETCODE_PERMUTATIONS_HPP
