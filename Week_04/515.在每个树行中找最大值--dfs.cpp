/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (61.73%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    18.7K
 * Total Submissions: 30.1K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, vector<int>& result, int level) {
        if (root == nullptr) return;
        while (level >= result.size()) result.push_back(INT_MIN);
        result[level] = max(result[level], root->val);
        dfs(root->left, result, level+1);
        dfs(root->right, result, level+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        dfs(root, result, 0);
        return result;
    }
};
// @lc code=end

