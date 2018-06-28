//
// Created by eyeboy on 2018/6/28.
//

#ifndef LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP
#define LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP

#include <vector>
#include <string>

using namespace std;

/**
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters.
 * 1()     2(abc) 3(def)
 * 4(ghi)  5(jkl) 6(mno)
 * 7(pqrs) 8(tuv) 9(wxyz)
 * Example:
    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
 namespace letter_combinations_of_a_phone_number {
     string digit_to_letters(char d) {
         switch(d) {
             case '2': return "abc";
             case '3': return "def";
             case '4': return "ghi";
             case '5': return "jkl";
             case '6': return "mno";
             case '7': return "pqrs";
             case '8': return "tuv";
             case '9': return "wxyz";
             default: return "";
         }
     }

     // brute force
     vector<string> solution_1(string digits) {
         int len = digits.size();
         vector<int> letter_idx;
         vector<string> letters;

         // init
         for(string::const_iterator iter = digits.cbegin(); iter != digits.cend(); ++iter) {
             letters.push_back(digit_to_letters(*iter));
             letter_idx.push_back(0);
         }

         vector<string> result;
         while(true) {
             string combination = "";
             for(int i = 0; i < len; ++i) {
                 string s = letters[i];
                 int index = letter_idx[i];
                combination += s[index];
             }
             result.push_back(combination);

             int j = len - 1;
             letter_idx[j] += 1;
             while(j >= 0) {
                 if(letter_idx[j] >= letters[j].size()) {
                     if(j == 0) {
                         return result;
                     } else {
                         letter_idx[j-1] += 1;
                         letter_idx[j] = 0;
                     }
                 } else {
                     break;
                 }
                 --j;
             }
         }
     }


     const vector<string> keyboard {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     void dfs(const string &digits, int depth, string path, vector<string> &result) {
         if(depth == digits.size()) {
             result.push_back(path);
             return;
         }

         string s = keyboard[digits[depth] - '0'];

         for(string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter) {
             dfs(digits, depth+1, path + (*iter), result);
         }
     }

     // depth first search
     vector<string> solution_2(string digits) {
         vector<string> result;

         if(digits.empty()) {
             return result;
         }

         string path;
         int depth = 0;
         dfs(digits, depth, path, result);

         return result;
     }
 }

#endif //LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP