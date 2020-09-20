/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {

    void generateAll(string& cur, int total, int open, int close, vector<string>& result) {
        if (open + close >= total) {
            result.push_back(cur);
            return;
        }
        if (open < total/2) {
            cur.push_back('(');
            generateAll(cur, total, open+1, close, result);
            cur.pop_back();
        }
        if (close < total/2 && close < open) {
            cur.push_back(')');
            generateAll(cur, total, open, close+1, result);
            cur.pop_back();
        } 
    }

public:

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        generateAll(cur, n * 2, 0, 0, result);
        return result;
    }
};
// @lc code=end

