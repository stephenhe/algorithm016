/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.87%)
 * Likes:    701
 * Dislikes: 0
 * Total Accepted:    118.7K
 * Total Submissions: 174K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> stack;
        if (preorder.size() <= 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push(root);
        int inorder_index = 0;
        for (int i = 1; i < preorder.size(); i++) {
            int preorder_value = preorder[i];
            TreeNode* node = stack.top();
            if (node->val != inorder[inorder_index]) {
                node->left = new TreeNode(preorder_value);
                stack.push(node->left);
            }
            else {
                while (!stack.empty() && stack.top()->val == inorder[inorder_index]) {
                    node = stack.top(); stack.pop();
                    ++inorder_index;
                }
                node->right = new TreeNode(preorder_value);
                stack.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

