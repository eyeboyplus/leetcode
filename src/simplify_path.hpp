//
// Created by eyeboy on 2018/9/25.
//

#ifndef LEETCODE_SIMPLIFY_PATH_HPP
#define LEETCODE_SIMPLIFY_PATH_HPP

#include <string>
#include <stack>

/**
 * Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"
In a UNIX-style file system, a period ('.') refers to the current directory,
 so it can be ignored in a simplified path. Additionally, a double period ("..")
 moves up a directory, so it cancels out whatever the last directory was.
 For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style
Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
 */

namespace simplify_path {
    using namespace std;

    string solution(string path) {
        stack<string> path_items;

        string item, ret;
        for(string::const_iterator iter = path.cbegin() + 1; iter != path.cend(); iter ++) {
            char c = *iter;

            if(c == '/') {

                if(item.empty())
                    continue;

                if(item.compare(".") == 0) {
                } else if(item.compare("..") == 0) {
                    if(!path_items.empty()) path_items.pop();
                } else {
                    path_items.push(item);
                }
                item.clear();
            } else {
                item.push_back(c);
            }
        }

        if(!item.empty()) {
            if(item.compare(".") == 0) {
            } else if(item.compare("..") == 0) {
                if(!path_items.empty()) path_items.pop();
            } else {
                path_items.push(item);
            }
        }

        if(path_items.empty()) {
            ret.push_back('/');
        } else {
            while(!path_items.empty()) {
                ret.insert(0, path_items.top());
                ret.insert(0, "/");
                path_items.pop();
            }
        }

        return ret;
    }
}

#endif //LEETCODE_SIMPLIFY_PATH_HPP
