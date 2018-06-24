/**
 * 
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 *   '?' Matches any single character.
 *   '*' Matches any sequence of characters (including the empty sequence).
 *   The matching should cover the entire input string (not partial).
 *   Note:
 *   s could be empty and contains only lowercase letters a-z.
 *   p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 * */

#include <string>
#include <iostream>

using namespace std;

// brute force
bool solution_1(string s, string p) {
    if(p.empty()) return s.empty();

    if(p.length() == 1) {
        if(p[0] == '*')
            return true;

        if(s.empty())
            return false;

        if(s.length() == 1)
            return p[0] == s[0] || p[0] == '?';
    }

    if(p[0] != '*') {
        return (p[0] == s[0] || p[0] == '?') && solution_1(s.substr(1), p.substr(1));
    } else {
        while(!s.empty()) {
            if(solution_1(s, p.substr(1))) return true;
            s = s.substr(1);
        }
        return solution_1(s, p.substr(1));
    }
}

int main(int argc, char **argv) {
    cout << solution_1("aa", "a") << endl;          // 0
    cout << solution_1("aa", "*") << endl;          // 1
    cout << solution_1("cb", "?a") << endl;         // 0
    cout << solution_1("adceb", "a*b") << endl;     // 1
    cout << solution_1("acdcb", "a*c?b") << endl;   // 0
    cout << solution_1("mississippi", "m??*ss*?i*pi") << endl;
    return 0;
}