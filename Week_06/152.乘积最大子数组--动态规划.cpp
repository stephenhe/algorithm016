/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.26%)
 * Likes:    795
 * Dislikes: 0
 * Total Accepted:    99.1K
 * Total Submissions: 244.8K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) return 0;
        if (size == 1) return nums[0];
        vector<int> maxDP(size); maxDP[0] = nums[0];
        vector<int> minDP(size); minDP[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < size; i++) {
            maxDP[i] = max(max(nums[i], maxDP[i-1]*nums[i]), minDP[i-1]*nums[i]);
            minDP[i] = min(min(nums[i], minDP[i-1]*nums[i]), maxDP[i-1]*nums[i]);
            res = max(res, maxDP[i]);
        }
        return res;
    }
};
// @lc code=end

