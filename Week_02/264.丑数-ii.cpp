/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        vector<int> uglys(n);
        uglys[0] = 1;
        int ret = 0;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int pn2 = uglys[p2] * 2, pn3 = uglys[p3] * 3, pn5 = uglys[p5] * 5;
            uglys[i] = min(min(pn2, pn3), pn5);
            if (uglys[i] == pn5) p5++;
            if (uglys[i] == pn3) p3++;
            if (uglys[i] == pn2) p2++;
        }
        ret = uglys[n-1];
        return ret;
    }
};
// @lc code=end

