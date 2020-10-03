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
        TreeNode* root = nullptr;
        if (preorder.size() == 0) return root;
        root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        vector<int> pvecl;
        vector<int> ivecl;
        vector<int> pvecr;
        vector<int> ivecr;
        bool front = true;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                front = false;
                continue;
            }
            if (front) ivecl.push_back(inorder[i]);
            else ivecr.push_back(inorder[i]);
        }       
        for (int i = 1; i < preorder.size(); i++) {
            if (i <= ivecl.size()) pvecl.push_back(preorder[i]);
            else pvecr.push_back(preorder[i]);
        }
        root->left = buildTree(pvecl, ivecl);
        root->right = buildTree(pvecr, ivecr);
        return root;
    }
};
// @lc code=end

