/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    double helper(double x, int n) {
        if (n == 0) return 1;
        double y = helper(x, n / 2);
        if (n % 2 == 0) return y * y;
        else return y * y * x;
    }
public:
    double myPow(double x, int n) {
        if (n >= 0)return helper(x, n);
        else return 1 / helper(x, n);
    }
};
// @lc code=end

