/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int total = 0;
        while (num > 9) {
            while (num > 0) {
                total += (num % 10);
                num /= 10;
            }
            num = total;
            total = 0;
            
        }
        return num;
    }
};
// @lc code=end

