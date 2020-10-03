/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.76%)
 * Likes:    930
 * Dislikes: 0
 * Total Accepted:    202K
 * Total Submissions: 262.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
    void backtrace(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums, int n, int k) {
        if (k >= n) {
            result.push_back(vec);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(vec.begin(), vec.end(), nums[i]) != vec.end()) continue;
            vec.push_back(nums[i]);
            backtrace(result, vec, nums, n, k + 1);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> vec;
        backtrace(result, vec, nums, nums.size(), 0);
        return result;
    }
};
// @lc code=end

