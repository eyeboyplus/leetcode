//
// Created by eyeboy on 2018/7/11.
//
#include "gtest/gtest.h"
#include "substring_with_concatenation_of_all_words.hpp"

#include <iostream>

using namespace substring_with_concatenation_of_all_words;

TEST(substring_with_concatenation_of_all_words, solution_1) {
    vector<string> words1 {"foo", "bar"};
    vector<int> res1 = solution_1("barfoothefoobarman", words1);

    vector<string> words2 {"word", "student"};
    vector<int> res2 = solution_1("wordgoodstudentgoodword", words2);

    vector<string> words3 {"word", "good", "best", "word"};
    vector<int> res3 = solution_1("wordgoodgoodgoodbestword", words3);

    vector<string> words4 {"bar", "foo", "the"};
    vector<int> res4 = solution_1("barfoofoobarthefoobarman", words4);

    vector<string> words5 {"fooo","barr","wing","ding","wing"};
    vector<int> res5 = solution_1("lingmindraboofooowingdingbarrwingmonkeypoundcake", words5);

    std::cout << "";
}