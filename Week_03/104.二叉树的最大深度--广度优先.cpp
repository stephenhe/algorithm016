/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        // recursion terminator
        if (root == nullptr) return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n ; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left != nullptr)q.push(node->left);
                if (node->right != nullptr)q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

