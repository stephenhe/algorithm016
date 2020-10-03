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
    unordered_map<int, int> inorder_map;
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend) {
        if (prestart > preend) return nullptr;

        int pre_root = prestart;
        int in_root = inorder_map[preorder[pre_root]];
        int left_size = in_root - instart;

        TreeNode* root = new TreeNode(preorder[pre_root]);
        root->left = myBuildTree(preorder, inorder, prestart + 1, prestart + left_size, instart, in_root - 1);
        root->right = myBuildTree(preorder, inorder, prestart + left_size + 1, preend, in_root + 1, inend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        TreeNode* root = myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
        return root;
    }
};
// @lc code=end

