/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    void helper(vector<int>& nums, vector<int> cur, int pos, vector<vector<int>>& ret) {
        if (pos >= nums.size()) {
            ret.push_back(cur);
            return;
        }
        helper(nums, cur, pos+1, ret);
        cur.push_back(nums[pos]);
        helper(nums, cur, pos+1, ret);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        helper(nums, cur, 0, ret);
        return ret;
    }
};
// @lc code=end

