//
// Created by eyeboy on 2018/7/23.
//

#ifndef LEETCODE_COMBINATION_SUM_II_HPP
#define LEETCODE_COMBINATION_SUM_II_HPP

#include <vector>
#include <algorithm>

/**
 * Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
    Each number in candidates may only be used once in the combination.
    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
 */
namespace combination_sum_ii {
    using namespace std;

    void recursive_combination_sum(vector<int> &candidates, int target,
                                   vector<int> &path, vector<vector<int>> &ret, int begin) {

        int len = candidates.size();

        if(target == 0) {
            ret.push_back(path);
            return;
        }

        int previous = -1;
        for(int i = begin; i < len && target >= candidates[i]; ++i) {
            // 同一层上相同的数值作用一样，直接跳过
            if(candidates[i] == previous)
                continue;
            else
                previous = candidates[i];
            path.push_back(candidates[i]);
            recursive_combination_sum(candidates, target - candidates[i], path, ret, i + 1);
            path.pop_back();
        }

    }

    vector<vector<int>> solution(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> path;
        vector<vector<int>> ret;

        recursive_combination_sum(candidates, target, path, ret, 0);

        return ret;
    }
}

#endif //LEETCODE_COMBINATION_SUM_II_HPP
