//
// Created by eyeboy on 2018/8/14.
//

#ifndef LEETCODE_QUICK_SORT_HPP
#define LEETCODE_QUICK_SORT_HPP

#include <vector>

namespace sort {
    using namespace std;

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int partition(vector<int> &nums, int start, int end) {
        int pivot_value = nums[end];
        for(int i = start - 1, j = start; j < end;) {
            int value = nums[j];
            if(value <= pivot_value) {
                i ++;
            } else {

            }
        }
    }

    void quicksort_recursive(vector<int> &nums, int start, int end) {
        if(end > start) {
            int pivot = partition(nums, start, end);
            quicksort_recursive(nums, start, pivot - 1);
            quicksort_recursive(nums, pivot + 1, end);
        }
    }

    void quicksort(vector<int> &nums) {
        quicksort_recursive(nums, 0, nums.size() - 1);
    }
}

#endif //LEETCODE_QUICK_SORT_HPP
