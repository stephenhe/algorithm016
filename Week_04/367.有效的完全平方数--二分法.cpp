/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.47%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 103.1K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;
        int ans = 0;
        while (l <= r) {
            long long mid = l + (r - l)/2;
            if (mid*mid <= num) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return (ans*ans == num);
    }
};
// @lc code=end

