/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            // ret.push_back(root->val);
            while (root != nullptr) {
                st.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            root = st.top(); st.pop();
            // ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};
// @lc code=end

