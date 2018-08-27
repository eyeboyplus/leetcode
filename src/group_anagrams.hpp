//
// Created by eyeboy on 2018/8/8.
//

#ifndef LEETCODE_GROUP_ANAGRAMS_HPP
#define LEETCODE_GROUP_ANAGRAMS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * Given an array of strings, group anagrams together.
 * Example:
    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    Note:
        All inputs will be in lowercase.
        The order of your output does not matter.
 */
namespace group_anagrams {
    using namespace std;

    vector<vector<string>> solution(vector<string> &strs) {
        unordered_map<string, vector<string>> res_map;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
            string s = *iter;
            string key = s;
            sort(key.begin(), key.end());
            if(res_map.find(key) == res_map.end()) {
                vector<string> vec = {s};
                res_map[key] = vec;
            } else {
                res_map[key].push_back(s);
            }
        }

        vector<vector<string>> ret;
        for(unordered_map<string, vector<string>>::iterator iter = res_map.begin();
                iter != res_map.end(); iter++) {
            ret.push_back(iter->second);
        }
        return ret;
    }
}

#endif //LEETCODE_GROUP_ANAGRAMS_HPP
