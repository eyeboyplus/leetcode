//
// Created by eyeboy on 2018/6/27.
//

#ifndef LEETCODE_LONGEST_COMMON_PREFIX_HPP
#define LEETCODE_LONGEST_COMMON_PREFIX_HPP

#include <string>
#include <vector>

using namespace std;

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    Example 1:
    Input: ["flower","flow","flight"]
    Output: "fl"

    Example 2:
    Input: ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

    Note: All given inputs are in lowercase letters a-z.
 */
namespace longest_common_prefix {
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        if(strs.empty())
            return result;

        if(strs.size() == 1)
            return strs[0];

        string first = strs[0];
        int len = first.size();

        for(int i=0; i<len; ++i) {
            bool flag = true;
            for(vector<string>::const_iterator iter = strs.cbegin() + 1; iter != strs.cend(); ++iter) {
                string s = *iter;
                if(i < s.size() && s[i] == first[i]) {
                    continue;
                } else {
                    return result;
                }
            }
            result.push_back(first[i]);
        }

        return result;
    }
}

#endif //LEETCODE_LONGEST_COMMON_PREFIX_HPP
