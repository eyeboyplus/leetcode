//
// Created by eyeboy on 2018/7/6.
//

#ifndef LEETCODE_IMPLEMENT_STR_STR_HPP
#define LEETCODE_IMPLEMENT_STR_STR_HPP

#include <string>

/**
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */
namespace implement_str_str {
    using namespace std;

    int solution_1(string haystack, string needle) {
        if(needle.empty())
            return 0;

        int l1 = haystack.size();
        int l2 = needle.size();

        for(int i = 0; i < l1; ++i) {
            int j = 0;
            while(j < l1 && j < l2 && haystack[i+j] == needle[j]) ++j;

            if(j == l2)
                return i;

            if(j == l1)
                return -1;
        }

        return -1;
    }
}

#endif //LEETCODE_IMPLEMENT_STR_STR_HPP
