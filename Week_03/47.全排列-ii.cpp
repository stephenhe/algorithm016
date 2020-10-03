/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (59.78%)
 * Likes:    480
 * Dislikes: 0
 * Total Accepted:    112.8K
 * Total Submissions: 182K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
    void traceback(vector<vector<int>>& result, vector<int>& nums, vector<int>& vec, vector<int>& rec, int k) {
        if (k >= nums.size()) {
            result.emplace_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (rec[i] || (i > 0 && nums[i] == nums[i - 1] && !rec[i-1])) continue;
            vec.emplace_back(nums[i]);
            rec[i] = 1;
            traceback(result, nums, vec, rec, k+1);
            vec.pop_back();
            rec[i] = 0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() <= 0) return result;
        vector<int> vec;
        vector<int> rec(nums.size());
        sort(nums.begin(), nums.end());
        traceback(result, nums, vec, rec, 0);
        return result;
    }
};
// @lc code=end

