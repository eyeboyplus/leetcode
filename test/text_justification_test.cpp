//
// Created by eyeboy on 2018/9/14.
//

#include "gtest/gtest.h"
#include "text_justification.hpp"

using namespace text_justification;

TEST(text_justification, solution) {
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res1 = solution(words1, 16);

    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> res2 = solution(words2, 16);

    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain",
                             "to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> res3 = solution(words3, 20);

    std::cout << "";
}