/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    void dfs(vector<string>& result, string& str, int n, int left, int right) {
        if (left == n && right == n) {
            result.push_back(str);
        }

        if (left < n) {
            str.push_back('(');
            dfs(result, str, n, left+1, right);
            str.pop_back();
        }
        if (left > right) {
            str.push_back(')');
            dfs(result, str, n, left, right+1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        dfs(result, str, n, 0, 0);
        return result;
    }
};
// @lc code=end

