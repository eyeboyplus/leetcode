//
// Created by eyeboy on 2018/8/30.
//

#ifndef LEETCODE_MERGE_INTERVALS_HPP
#define LEETCODE_MERGE_INTERVALS_HPP

#include <vector>
#include <algorithm>

/**
 * Given a collection of intervals, merge all overlapping intervals.
Example 1:
    Input: [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
    Input: [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 */
namespace merge_intervals {
    using namespace std;

    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };

    bool cmp(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }

    vector<Interval> solution(vector<Interval> &intervals) {
        vector<Interval> ret;

        if(intervals.empty())
            return ret;

        sort(intervals.begin(), intervals.end(), cmp);

        ret.push_back(intervals[0]);
        for(vector<Interval>::iterator iter = intervals.begin() + 1;
                iter != intervals.end(); iter++) {
            Interval i = ret.back();
            Interval j = *iter;
            if(j.start >= i.start && j.start <= i.end) {
                Interval interval (i.start, j.end > i.end ? j.end : i.end);
                ret.pop_back();
                ret.push_back(interval);
            } else {
                ret.push_back(j);
            }
        }
        return ret;
    }
}

#endif //LEETCODE_MERGE_INTERVALS_HPP
