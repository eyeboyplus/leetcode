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

    // 回溯实现
    void recursive_sum(vector<int> &candidates, int target,
                     vector<int> &path, vector<vector<int>> &ret, int begin) {
        // i.e., path数组中的值之和等于target
        if(target == 0) {
            ret.push_back(path);
            return;
        }

        int len = candidates.size();
        // candidates 数组为升序，begin之前的数无须再参加操作，去重
        for(int i = begin; i < len && target >= candidates[i]; ++i) {
            // candidates[i]值小于等于target,可能是构成target的数值，加入path中
            path.push_back(candidates[i]);
            // 递归计算剩余值，如果组合之和等于target，这些组合已经加入到结果集ret中
            recursive_sum(candidates, target - candidates[i], path, ret, i);
            // 从组合中弹出上次计算的值，准备尝试下一个
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
