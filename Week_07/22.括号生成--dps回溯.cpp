/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    void helper(vector<string>& result, string str, int n, int left, int right) {
        if (left == n && right == n) {
            result.push_back(str);
            return;
        }
        if (left < n) helper(result, str+'(', n, left+1, right);
        if (right < left) helper(result, str+')', n, left, right+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) return result;
        string str;
        helper(result, str, n, 0, 0);
        return result;
    }
};
// @lc code=end

