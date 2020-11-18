/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.86%)
 * Likes:    558
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 300.5K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 题目数据保证答案肯定是一个 32 位的整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "12"
 * 输出：2
 * 解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "226"
 * 输出：3
 * 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "0"
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "1"
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "2"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 只包含数字，并且可能包含前导零。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n < 1 || s[0] == '0') return 0;
        vector<int> dp(n+1, 1);
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')
                    dp[i+1] = dp[i-1];
                else
                    return 0;
            }
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                dp[i+1] = dp[i] + dp[i-1];
            }
            else {
                dp[i+1] = dp[i];
            }
        }
        return dp[n];
    }
};
// @lc code=end

