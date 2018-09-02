//
// Created by eyeboy on 2018/9/2.
//

#ifndef LEETCODE_LENGTH_OF_LAST_WORD_HPP
#define LEETCODE_LENGTH_OF_LAST_WORD_HPP

#include <string>

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
    If the last word does not exist, return 0.
    Note: A word is defined as a character sequence consists of non-space characters only.
Example:
    Input: "Hello World"
    Output: 5
 */
namespace length_of_last_word {
    using namespace std;

    int solution(string s) {
        int len = s.size();

        int end = len - 1;
        for(; end >= 0 && s[end] == ' '; --end);

        if(end == -1)
            return 0;

        int start = end;
        for(; start >=0 && s[start] != ' '; --start);

        return end - start;
    }
}

#endif //LEETCODE_LENGTH_OF_LAST_WORD_HPP
