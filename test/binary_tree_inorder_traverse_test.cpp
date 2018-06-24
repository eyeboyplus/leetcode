//
// Created by eyeboy on 2018/6/24.
//
#include <gtest/gtest.h>
#include "binary_tree_inorder_traverse.hpp"

class BinTreeInorderTraverseTest : public testing::Test {
protected:
    void SetUp() override {
        root = new TreeNode(1);
        TreeNode *node1 = new TreeNode(2);
        root->right = node1;
        TreeNode *node2 = new TreeNode(3);
        node1->left = node2;
    }

    void TearDown() override {
    }

    TreeNode *root;
};

TEST_F(BinTreeInorderTraverseTest, solution_1) {
    solution_1(root);
}

TEST_F(BinTreeInorderTraverseTest, solution_2) {
    solution_2(root);
}
