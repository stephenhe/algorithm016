/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 *
 * https://leetcode-cn.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (75.93%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 74.9K
 * Testcase Example:  '"Hello"'
 *
 * 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: "Hello"
 * 输出: "hello"
 * 
 * 示例 2：
 * 
 * 
 * 输入: "here"
 * 输出: "here"
 * 
 * 示例 3：
 * 
 * 
 * 输入: "LOVELY"
 * 输出: "lovely"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        string result(str);
        int st = 'A' - 'a';
        for (int i = 0; i < result.length(); i++) {
            if (result[i] >= 'A' && result[i] <= 'Z') result[i] = result[i] - st;
        }
        return result;
    }
};
// @lc code=end

