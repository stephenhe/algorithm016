/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void helper(Node* root, vector<int>& v) {
        if (root == nullptr) return;
        for (Node* n : root->children) {
            helper(n, v);
        }
        v.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
};
// @lc code=end

