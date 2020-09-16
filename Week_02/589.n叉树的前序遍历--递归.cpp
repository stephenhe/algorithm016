/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> ret;
public:
    vector<int> preorder(Node* root) {
        
        if (root == nullptr) return ret;
        ret.push_back(root->val);
        for (auto i : root->children) {
            preorder(i);
        }
        return ret;
    }
};
// @lc code=end

