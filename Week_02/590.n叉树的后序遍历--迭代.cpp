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
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top(); st.pop();
            ret.push_back(node->val);
            for (auto child : node->children) {
                st.push(child);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

