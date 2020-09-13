/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int n = height.size();
        if (n < 3) return 0;
        int* left = new int[n];
        left[0] = height[0];
        int* right = new int[n];
        right[n-1] = height[n-1];
        // int right[n];// = {height[n - 1]};
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i>= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            int min_num = min(left[i], right[i]);
            if (min_num > height[i]) {
                ret += (min_num - height[i]);
            }
        }
        return ret;
    }
};
// @lc code=end

