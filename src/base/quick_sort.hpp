//
// Created by eyeboy on 2018/8/14.
//

#ifndef LEETCODE_QUICK_SORT_HPP
#define LEETCODE_QUICK_SORT_HPP

#include <vector>
#include <ctime>
#include <cstdlib>

namespace base {
    using namespace std;

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int partition(vector<int> &nums, int start, int end) {
        int x = nums[end];
        int i = start - 1, j = start;
        for(; j <= end - 1; ++j) {
            if(nums[j] <= x) {
                swap(nums, ++i, j);
            }
        }
        swap(nums, end, i + 1);

        return i + 1;
    }

    int randomized_partition(vector<int> &nums, int start, int end) {
        std::srand(time(0));
        int i = (rand() % (end - start + 1)) + start;
        swap(nums, i, end);
        return partition(nums, start, end);
    }

    void quick_sort(vector<int> &nums, int start, int end) {
        if(end > start) {
            int q = partition(nums, start, end);
            quick_sort(nums, start, q - 1);
            quick_sort(nums, q + 1, end);
        }
    }
}

#endif //LEETCODE_QUICK_SORT_HPP
