//
// Created by eyeboy on 2018/9/3.
//

#ifndef LEETCODE_INSERTION_SORT_HPP
#define LEETCODE_INSERTION_SORT_HPP

#include <vector>

namespace base {
    using namespace std;
    void insertion_sort(vector<int> &nums, int start, int end) {
        for(int i = start; i <= end; ++i) {
            int target = nums[i];
            int j = start;
            for(; j < i && nums[j] < target; ++j);
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin() + j, target);
        }
    }
}

#endif //LEETCODE_INSERTION_SORT_HPP
