/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* ln = lowestCommonAncestor(root->left, p, q);
        TreeNode* rn = lowestCommonAncestor(root->right, p, q);
        if (ln == nullptr) return rn;
        if (rn == nullptr) return ln;
        if (ln && rn) return root;
        return nullptr;
    }
};
// @lc code=end

