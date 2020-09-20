/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    double helper(double x, long long n) {
        double c_x = x;
        double ret = 1.0;
        while (n > 0) {
            if (n % 2 == 1) {
                ret *= c_x;
            }
            c_x *= c_x;
            n /= 2;
        }
        return ret;
    }
public:
    double myPow(double x, int n) {
        if (n >= 0)return helper(x, n);
        else return (1.0 / helper(x, -(long long)n));
    }
};
// @lc code=end

