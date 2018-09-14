//
// Created by eyeboy on 2018/9/14.
//

#ifndef LEETCODE_TEXT_JUSTIFICATION_HPP
#define LEETCODE_TEXT_JUSTIFICATION_HPP

#include <vector>
#include <string>

/**
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is,
 pack as many words as you can in each line. Pad extra spaces ' '
 when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible.
 If the number of spaces on a line do not divide evenly between words,
 the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:
    Input:
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    Output:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]
Example 2:
    Input:
    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    Output:
    [
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
    ]
    Explanation: Note that the last line is "shall be    " instead of "shall     be",
                 because the last line must be left-justified instead of fully-justified.
                 Note that the second line is also left-justified becase it contains only one word.
Example 3:
    Input:
    words = ["Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    Output:
    [
      "Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
]
 */
namespace text_justification {
    using namespace std;

    vector<string> solution(vector<string> &words, int maxWidth) {
        vector<string> ret;

        int totalWordWidth= 0, wordCount = 0;
        vector<string>::const_iterator start = words.begin();
        for(vector<string>::const_iterator iter = words.begin();
                iter != words.end(); iter++) {
            string word = *iter;

            if(word.size() + totalWordWidth + wordCount <= maxWidth) {
                totalWordWidth += word.size();
                wordCount ++;
            } else {
                string line;
                if(wordCount == 1) {
                    int spaceCount = maxWidth - totalWordWidth;
                    line.append(*start);
                    start ++;
                    line.insert(line.end(), spaceCount, ' ');
                } else {
                    int spaceCount = maxWidth - totalWordWidth;
                    int quotient = spaceCount / (wordCount - 1);
                    int remainder = spaceCount % (wordCount - 1);
                    int interval = wordCount - 1;
                    while (start != iter) {
                        line.append(*start);
                        if (interval > 0) {
                            line.insert(line.end(), remainder > 0 ? quotient + 1 : quotient, ' ');
                            remainder--;
                            interval --;
                        }
                        start ++;
                    }
                }

                ret.push_back(line);
                std::cout << line.size() << std::endl;

                totalWordWidth = word.size();
                wordCount = 1;
            }
        }

        if(start != words.end()) {
            string line;
            line.append(*start);
            while(start + 1 != words.end()) {
                line.append(" ");
                line.append(*(start + 1));
                start += 1;
            }
            line.insert(line.end(), maxWidth - totalWordWidth - wordCount + 1, ' ');
            ret.push_back(line);
            std::cout << line.size() << std::endl;
        }
        return ret;
    }
}

#endif //LEETCODE_TEXT_JUSTIFICATION_HPP
