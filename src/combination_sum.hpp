//
// Created by eyeboy on 2018/7/20.
//

#ifndef LEETCODE_COMBINATION_SUM_HPP
#define LEETCODE_COMBINATION_SUM_HPP

#include <vector>
#include <algorithm>

/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
    The same repeated number may be chosen from candidates unlimited number of times.
    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
 */
namespace combination_sum {
    using namespace std;

    void recursive_sum(vector<int> &candidates, int target,
                     vector<int> &path, vector<vector<int>> &ret, int begin) {
        if(target == 0) {
            ret.push_back(path);
            return;
        }

        int len = candidates.size();
        for(int i = begin; i < len && target >= candidates[i]; ++i) {
            path.push_back(candidates[i]);
            recursive_sum(candidates, target - candidates[i], path, ret, i);
            path.pop_back();
        }
    }

    vector<vector<int>> solution(vector<int> &candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> path;
        vector<vector<int>> ret;
        recursive_sum(candidates, target, path, ret, 0);
        return ret;
    }
}

#endif //LEETCODE_COMBINATION_SUM_HPP
