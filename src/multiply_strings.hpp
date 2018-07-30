//
// Created by eyeboy on 2018/7/27.
//

#ifndef LEETCODE_MULTIPLY_STRINGS_HPP
#define LEETCODE_MULTIPLY_STRINGS_HPP

#include <string>
#include <stack>

/**
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 */
namespace multiply_strings {
    using namespace std;

    string multiply(string num, char c) {
        if(c == '0')
            return "0";

        int len = num.size(), i = 0;
        while(i < len && num[i] == 0) i++;

        if(i == len)
            return "0";

        num = num.substr(i);

        int carry = 0;
        for(string::reverse_iterator iter = num.rbegin();
                iter != num.rend(); iter++) {
            int d = (((*iter) - '0') * (c - '0')) + carry;

            *iter = (d % 10) + '0';
            carry = d / 10;
        }

        if(carry != 0)
            num.insert(0, 1, carry + '0');

        return num;
    }

    string add_two_string(string num1, string num2) {
        stack<char> stack1, stack2, ret_stack;
        for(string::const_iterator iter = num1.cbegin(); iter != num1.cend(); iter++) stack1.push(*iter);
        for(string::const_iterator iter = num2.cbegin(); iter != num2.cend(); iter++) stack2.push(*iter);

        int carry = 0;
        while(!stack1.empty() && !stack2.empty()) {
            int d = (stack1.top() - '0') + (stack2.top() - '0') + carry;
            stack1.pop(); stack2.pop();
            ret_stack.push((d % 10) + '0');
            carry = d / 10;
        }

        while(!stack1.empty()) {
            int d = (stack1.top() - '0') + carry;
            stack1.pop();
            ret_stack.push((d % 10) + '0');
            carry = d / 10;
        }
        while(!stack2.empty()) {
            int d = (stack2.top() - '0') + carry;
            stack2.pop();
            ret_stack.push((d % 10) + '0');
            carry = d / 10;
        }
        if(carry != 0)
            ret_stack.push(carry + '0');

        string ret;
        while(!ret_stack.empty()) {
            ret.push_back(ret_stack.top());
            ret_stack.pop();
        }

        int i = 0, len = ret.length();
        while(i < len && ret[i] == '0') i++;

        if(i == len)
            return "0";

        return ret.substr(i);
    }

    string solution(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();

        string ret = "0";
        for(int i = len1 - 1; i >= 0; --i) {
            string internal = multiply(num2, num1[i]);
            internal.insert(internal.length(), len1 - 1 - i, '0');
            ret = add_two_string(ret, internal);
        }

        return ret;
    }
}

#endif //LEETCODE_MULTIPLY_STRINGS_HPP
