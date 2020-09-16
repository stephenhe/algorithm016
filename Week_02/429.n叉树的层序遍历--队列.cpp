/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
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
    void dfs(Node *root, int depth) {

    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> r;
            for (int i = 0; i < n; i++) {
                Node *node = q.front(); q.pop();
                r.push_back(node->val);
                for (Node* i : node->children) {
                    q.push(i);
                }
            }
            ret.push_back(r);
        }
        return ret;
    }
};
// @lc code=end

