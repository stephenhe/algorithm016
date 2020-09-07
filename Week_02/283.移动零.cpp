/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int last_non_zero = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                if (cur > last_non_zero) {
                    nums[last_non_zero] = nums[cur];
                    nums[cur] = 0;
                }
                last_non_zero++;
            }
        }
    }
};
// @lc code=end

