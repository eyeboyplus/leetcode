//
// Created by eyeboy on 2018/7/11.
//

#ifndef LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_HPP
#define LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_HPP

#include <vector>
#include <string>
#include <unordered_map>

/**
 * You are given a string, s, and a list of words, words,
 * that are all of the same length. Find all starting indices
 * of substring(s) in s that is a concatenation of each word in
 * words exactly once and without any intervening characters.
    Example 1:
    Input:
      s = "barfoothefoobarman",
      words = ["foo","bar"]
    Output: [0,9]
    Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
    The output order does not matter, returning [9,0] is fine too.
 */
namespace substring_with_concatenation_of_all_words {

    using namespace std;

    // O(n^2), O(1)
    vector<int> solution_1(string s, vector<string> &words) {
        unordered_map<string, int> map;
        unordered_map<string, int> word_map;

        int s_len = s.size();
        vector<int> result;

        if(words.empty())
            return result;

        int word_len = words[0].size();

        // init word map
        for(vector<string>::const_iterator iter = words.cbegin();
                iter != words.cend(); ++iter) {
            if(map.find(*iter) == map.end())
                map[*iter] = 1;
            else
                map[*iter] += 1;
        }

        int word_cnt = words.size();
        int all_word_len = word_cnt * word_len;

        for(int i = 0; i < s_len - all_word_len + 1; ++i) {
            int cnt = 0, idx = -1;
            word_map = map;

            for(int j = 0; j < word_cnt; ++j) {
                // s 中的 word
                string sub_s = s.substr(i + j * word_len, word_len);

                unordered_map<string, int>::iterator iter = word_map.find(sub_s);

                // 判断word_map中是否有该word
                if(iter == word_map.end()) {
                    break;
                } else {
                    if(word_map[sub_s] > 0) {       // word的个数是否大于0
                        if(cnt == 0)
                            idx = i;
                        cnt ++;
                        word_map[sub_s] -= 1;
                    } else {
                        break;
                    }
                }
            }

            if(cnt == word_cnt)
                result.push_back(idx);

        }

        return result;
    }

}

#endif //LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_HPP
