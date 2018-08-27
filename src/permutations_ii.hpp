//
// Created by eyeboy on 2018/8/6.
//

#ifndef LEETCODE_PERMUTATIONS_II_HPP
#define LEETCODE_PERMUTATIONS_II_HPP

#include <vector>
#include <algorithm>

/**
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
    Example:
        Input: [1,1,2]
        Output:[[1,1,2],[1,2,1],[2,1,1]]
 */
namespace permutations_ii {
    using namespace std;

    void recursive(vector<int> nums, vector<int> path, vector<vector<int>> &ret) {
        if(nums.empty()) {
            ret.push_back(path);
            return;
        }

        int pre = -1;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            int num = *iter;
            if(iter == nums.begin()) {
                pre = num;
                path.push_back(num);
            } else {
                if(num == pre) {
                    continue;
                } else {
                    path.push_back(num);
                    pre = num;
                }
            }

            vector<int> temp;
            if(iter - 1 >= nums.begin())
                temp.insert(temp.end(), nums.begin(), iter);
            if(iter + 1 <= nums.end())
                temp.insert(temp.end(), iter + 1, nums.end());
            recursive(temp, path, ret);
            path.pop_back();
        }
    }

    vector<vector<int>> solution(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        recursive(nums, path, ret);
        return ret;
    }
}

#endif //LEETCODE_PERMUTATIONS_II_HPP
