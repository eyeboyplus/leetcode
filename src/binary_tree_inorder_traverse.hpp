//
// Created by eyeboy on 2018/6/24.
//

#ifndef LEETCODE_BINARY_TREE_INORDER_TRAVERSE_HPP
#define LEETCODE_BINARY_TREE_INORDER_TRAVERSE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

// recursive
vector<int> solution_1(TreeNode* root) {
    vector<int> result;

    if(root == NULL)
        return result;

    vector<int> leftVec = solution_1(root->left);
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.push_back(root->val);
    vector<int> rightVec = solution_1(root->right);
    result.insert(result.end(), rightVec.begin(), rightVec.end());

    return result;
}

// stack
vector<int> solution_2(TreeNode *root) {
    vector<int> result;

    if(root == NULL)
        return result;

    TreeNode *curNode = root;
    stack<TreeNode*> stack;

    while(curNode || !stack.empty()) {
        if(curNode) {
            stack.push(curNode);
            curNode = curNode->left;
        } else if(!stack.empty()) {
            result.push_back(stack.top()->val);
            curNode = stack.top()->right;
            stack.pop();
        }
    }

    return result;
}

#endif //LEETCODE_BINARY_TREE_INORDER_TRAVERSE_HPP
