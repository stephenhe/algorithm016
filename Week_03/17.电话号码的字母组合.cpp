/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.43%)
 * Likes:    939
 * Dislikes: 0
 * Total Accepted:    181.9K
 * Total Submissions: 327.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
    void traceback(vector<string>& result, string digits, string& ret, unordered_map<char, string> mp, int idx) {
        if (idx >= digits.length()) {
            result.push_back(ret);
        }

        string st = mp[digits[idx]];
        for (const char& chr : st) {
            ret.push_back(chr);
            traceback(result, digits, ret, mp, idx+1);
            ret.pop_back();
        }
        
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) return result;
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string ret;
        traceback(result, digits, ret, mp, 0);
        return result;
    }
};
// @lc code=end

