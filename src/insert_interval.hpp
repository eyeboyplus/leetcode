//
// Created by eyeboy on 2018/8/31.
//

#ifndef LEETCODE_INSERT_INTERVAL_HPP
#define LEETCODE_INSERT_INTERVAL_HPP

#include <vector>

/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */
namespace insert_interval {
    using namespace std;

    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int start, int end) : start(start), end(end) {}
    };

    vector<Interval> merge(vector<Interval> &intervals) {
        // sorted intervals
        vector<Interval> ret;
        if(intervals.empty())
            return ret;

        ret.push_back(intervals[0]);
        for(vector<Interval>::iterator iter = intervals.begin() + 1; iter != intervals.end();
                iter++) {
            Interval target = *iter;
            Interval last = ret.back();
            if(target.start > last.end) {
                ret.push_back(target);
            } else {
                Interval interval = Interval(last.start, last.end > target.end ? last.end : target.end);
                ret.pop_back();
                ret.push_back(interval);
            }
        }
        return ret;
    }

    vector<Interval> solution(vector<Interval> &intervals, Interval interval) {
        vector<Interval>::iterator iter = intervals.begin();

        for(;iter != intervals.end() && (*iter).start < interval.start; ++iter);

        intervals.insert(iter, interval);
        return merge(intervals);
    }
}


#endif //LEETCODE_INSERT_INTERVAL_HPP
