// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return (left->val == right->val) && compare(left->left, right->right) && compare(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
// @lc code=end

